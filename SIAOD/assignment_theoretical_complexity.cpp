#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> create_matrix(int rows, int columns){

    vector<vector<int>> matrix;
    for (int i =0;i<rows;i++){
        vector<int> local;
        for (int j  =0; j<columns;j++){
            local.push_back(rand()%100-100);
        }
        matrix.push_back(local);
    }
    return matrix;
}

int main(){
    vector<vector<int>> matrix;
    cout<<"Size: \n"; // >2
    int size;
    cin>>size;
    matrix = create_matrix(size, size);
    
    int min_even=INT16_MAX;
    for (int i =0;i<size;i++){
        for (int j  =0; j<size;j++){
            //cout<<matrix[i][j]<<" ";
            if (i==j || (i+j)%(size-1)==0){
                continue;
            }else{
                if (matrix.at(i).at(j)%2==0 && matrix[i][j]<min_even){
                    min_even = matrix[i][j];
                }
            }
        }
    }
    cout<<"\nResult is: "<<min_even;
    int n;
    cin>>n;

    return 0;
    }
