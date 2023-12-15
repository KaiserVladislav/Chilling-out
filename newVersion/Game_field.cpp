#include "Game_field.h"
#include "Herbivore.h"
#include "Carnivore.h"
#include "Actions.h"
#include "Carnivore.cpp"

//static members have to be declared beforehand
int Game_field::x;
int Game_field::y;
int Game_field::c;
int Game_field::h;
int Game_field::empty_tiles_percent;
vector<Carnivore> Game_field::carnivores;
vector<Herbivore> Game_field::herbivores;
vector<vector<string>> Game_field::game_field;

//constructor for basic preset
Game_field::Game_field(vector<int> preset){
    x=preset[0];
    y=preset[1];
    c=preset[2];
    h=preset[3];
    empty_tiles_percent=preset[4];

    carnivores.reserve(c);
    herbivores.reserve(h);
    
    generateField(x,y,empty_tiles_percent);
}

// constructor for fully customized preset
Game_field::Game_field(vector<vector<vector<int>>> preset){
    vector<int> mainSettings = preset[0][0];
    x = mainSettings[0];
    y = mainSettings[1];
    c = mainSettings[2];
    h = mainSettings[3];
    empty_tiles_percent = mainSettings[4];
        
    herbivores.reserve(h);
    carnivores.reserve(c);
        
    Carnivore::setAgeCap(mainSettings[5]);
    Herbivore::setAgeCap(mainSettings[6]);

    vector<vector<int>> positions = preset[1];

    if (positions.empty()) {
         generateField(x,y,empty_tiles_percent);
    } else {
        for (int i = 0; i < c; ++i) {
            carnivores.emplace_back(i, positions[i]);
        }

        for (int i = c; i < positions.size(); ++i) {
            herbivores.emplace_back(i, positions[i]);
        }

        generateField(x,y,empty_tiles_percent,carnivores, herbivores);
    }
}

// simplistic creation of gamefield 
void Game_field::generateField(int x, int y, int empty_tiles_percent){
        game_field = vector<vector<string>>(y, vector<string>(x, "-"));
        // Calculate the number of grass tiles based on empty_tiles_percent
        int totalTiles = x * y;
        int emptyTiles = (empty_tiles_percent * totalTiles) / 100;
        int grassTiles = totalTiles - emptyTiles;
        // Fill the required number of grass tiles
        while (grassTiles > 0) {
            int row = rand() % y;
            int col = rand() % x;

            if (game_field[row][col] == "-") {
                game_field[row][col] = "+";
                grassTiles--;
            }
        }
        // Random emplacement of Carnivores and Herbivores
        int indexH = 0, indexC = 0;
        int localC = getC();
        int localH = getH();

        while (localC > 0 || localH > 0) {
            if (localC > 0) {
                int row = rand() % y;
                int col = rand() % x;

                while (game_field[row][col] == "H") {
                    row = rand() % y;
                    col = rand() % x;
                }

                //carnivores.emplace_back(indexC++, array<int, 2>{row, col}, "C");
                Carnivore cv(indexC,{row,col});
                carnivores.emplace_back(cv);
                game_field[row][col] = "C";
                localC--;
            }

            if (localH > 0) {
                int row = rand() % y;
                int col = rand() % x;

                while (game_field[row][col] == "C") {
                    row = rand() % y;
                    col = rand() % x;
                }

                //herbivores.emplace_back(indexH++, array<int, 2>{row, col}, "H");
                Herbivore hb(indexC,{row,col});
                herbivores.emplace_back(hb);
                game_field[row][col] = "H";
                localH--;
            }
        }
}

//intricate creation of gamefield
void Game_field::generateField(int x, int y, int empty_tiles_percent, vector<Carnivore> carnivores, vector<Herbivore> herbivores){
    Game_field::game_field = vector<vector<string>>(y, vector<string>(x, "-"));
        // Calculate the number of grass tiles based on empty_tiles_percent
        int totalTiles = x * y;
        int emptyTiles = (empty_tiles_percent * totalTiles) / 100;
        int grassTiles = totalTiles - emptyTiles;
        // Fill the required number of grass tiles
        while (grassTiles > 0) {
            int row = rand() % y;
            int col = rand() % x;

            if ( Game_field::game_field[row][col] == "-") {
                Game_field::game_field[row][col] = "+";
                grassTiles--;
            }
        }
        // Emplacement of Carnivores and Herbivores
        for (Carnivore cv : carnivores) {
            vector<int> position = cv.getPosition();
            Game_field::game_field[position[0]][position[1]] = "C";
        }

        for (Herbivore hb : herbivores) {
            vector<int> position = hb.getPosition();
            Game_field::game_field[position[0]][position[1]] = "H";
        }
}

void Game_field::print(){
    int c_g=0;
    int c_e=0;

    for(int i =0;i<game_field.size();i++){
        for (int j = 0; j < game_field[i].size(); j++){
            cout<<game_field[i][j]<<" ";
            if(game_field[i][j].compare("-")==0){
                c_e++;
            }else if(game_field[i][j].compare("+")==0) {
                c_g++;
            }
        }
        cout<<endl;
    }
        
    cout<<"Carnivores left: "<<getCarnivores().size()<<endl;
    cout<<"Herbivores left: "<<getHerbivores().size()<<endl;
    cout<<"Grass tiles left: "<<c_g<<endl;
    cout<<"Empty tiles left: "<<c_e<<endl;
    cout<<"MOVE ITERATION: "<<Actions::getIteration();
    cout<<"Carnivores dead: "<<getC()-getCarnivores().size()<<endl;
    cout<<"Herbivores dead: "<<getH()-getHerbivores().size()<<endl;
        
    // if gameover....  
    if(Actions::isGameOverE()){
            cout<<"The game is over. Everybody is dead!\n";
            exit(0);
    }
    else if(Actions::isGameOverC()){
        cout<<"The game is over. All carnivores are dead!\n";
        exit(0);
    }
    else if(Actions::isGameOverH()){
        cout<<"The game is over. All herbivores are dead!\n";
        exit(0);
    }

    // looping the game process
    cout<<"TO CONTINUE, ENTER 1; ELSE 0\n";
    string response;
    getline(cin,response);
    if(response.compare("1")==0){
        play();
        // forced game shutdown
    }else if (response.compare("0")==0){
        exit(0);
    }
}


int Game_field::getX(){return x;}
int Game_field::getY(){return y;}
int Game_field::getC(){return c;}
int Game_field::getH(){return h;}

vector<Herbivore> Game_field::getHerbivores(){return herbivores;}
vector<Carnivore> Game_field::getCarnivores(){return carnivores;}

    //getRandom?
string Game_field::getTile(vector<int> position){
    return Game_field::game_field[position[0]][position[1]];
    }

Herbivore Game_field::getHerbivoreByPosition(vector<int> position){
    vector<Herbivore> herbivores = getHerbivores();
    for (Herbivore hb : herbivores) {
        if(hb.getPosition()==position){
            return hb;
        }
    }
    //return NULL;;
}
Carnivore Game_field::getCarnivoreByPosition(vector<int> position){
    vector<Carnivore> carnivores = getCarnivores();
    for(Carnivore cv : carnivores){
        if(cv.getPosition()==position){
            return cv;
        }
    //return NULL;;
    }
}