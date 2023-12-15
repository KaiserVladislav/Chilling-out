#include <iostream>
#include <vector>
#include "Game_field.h"
#include "Game_field.cpp"
using namespace std;


// Function to choose basic preset
vector<int> choosePreset() {
    cout<<"You've chosen to use prepared game preset.\n";
    int presets[3][5] = {
        {50, 50, 10, 20, 30},
        {100, 100, 30, 40, 30},
        {200, 200, 50, 60, 30}
    };

    cout << "Select game preset:" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Preset " << i + 1 << ": \nX: " << presets[i][0] << "\nY: " << presets[i][1]
                  << "\nTotal carnivores: " << presets[i][2] << "\nTotal herbivores: " << presets[i][3]
                  << "\nPercentage of empty tiles: " << presets[i][4] << "%" << endl << endl;
    }

    cout << "Your choice: ";
    int response;
    cin >> response;

    if (response == 1) {
        return {presets[0], presets[1]};
    } else if (response == 2) {
        return {presets[1], presets[2]};
    } else if (response == 3) {
        return {presets[2], presets[0]};
    } else {
        cout << "Invalid input. Restarting program..." << endl;
        return choosePreset();
    }
}

// Function to get custom positions
vector<vector<int>> getCustomizedPositions(int amountOfAnimals, int id) {
    vector<vector<int>> positions;

    for (int i = 1; i <= amountOfAnimals; i++) {
        int x, y;
        if (id == 0) {
            cout << "Carnivore no. " << i << endl;
        } else {
            cout << "Herbivore no. " << i << endl;
        }

        cout << "X: ";
        cin >> x;
        cout << "Y: ";
        cin >> y;

        positions.push_back({y, x});
    }

    return positions;
}

// Function to get custom preset
vector<vector<vector<int>>> fullyCustomizedPreset() {//literally 3d matrix
    cout << "You've chosen to edit the starting game preset." << endl;
    cout << "Field parameters: " << endl;
    int x, y, emptyTiles;
    cout << "X: ";
    cin >> x;
    cout << "Y: ";
    cin >> y;
    cout << "Percentage of empty tiles: ";
    cin >> emptyTiles;

    int c,h,c_age_cap,h_age_cap;
    cout<<"Animals' parameters:\n";
    cout<<"Amount of carnivores: ";
    cin>>c;
    cout<<"Amount of herbivores: ";
    cin>>h;
    cout<<"Max age of carnivore: ";
    cin>>c_age_cap;
    cout<<"Max age of herbivore: ";
    cin>>h_age_cap;

    vector<vector<int>> main_preset;
    // solid solution......
    main_preset.push_back({{x,y,c,h,emptyTiles,c_age_cap,h_age_cap}});

    vector<vector<vector<int>>> result;
    result.push_back(main_preset);

    cout << "Do you want to manually place animals?\n";
    string response;
    cin.ignore();
    getline(cin, response);
    vector<vector<int>> positions;
    
    if (response == "Yes" || response == "yes" || response == "YES") {
        vector<vector<int>> positionsC = getCustomizedPositions(c, 0);
        vector<vector<int>> positionsH = getCustomizedPositions(h, 1);
        // cpp specific
        positions.insert(positions.end(), positionsC.begin(), positionsC.end());
        positions.insert(positions.end(), positionsH.begin(), positionsH.end());
    }

    result.push_back(positions);
    cout << "Customization process has been completed." << endl;
    return result;
}

void initiate_settings(){
    cout<<"Do you want to customize starting parameters?\n";
    string response;
    getline(cin,response);
    if(response.compare("yes")==0||response.compare("Yes")==0||response.compare("Yes")==0){
        vector<vector<vector<int>>> preset = fullyCustomizedPreset();
        //GameField(preset);
    }else{
        vector<int> preset = choosePreset();
        cout<<Game_field::getC();
        //Game_field::gameField(preset);
        //Game_field::print();
    }
    
    
}

int main() {
    initiate_settings();
    return 0;
}
