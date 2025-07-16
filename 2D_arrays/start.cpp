#include<iostream>
using namespace std ;

int main(){
    int rows = 3 ; 
    int cols = 3 ; 

    int mat[rows][cols]  ; 

    //input
     for(int i = 0 ; i<rows ; i++){
        for(int j = 0 ; j< cols ; j++){
            cin >> mat[i][j] ;
        }
     }

    // output
    for(int i = 0 ; i<rows ; i++){
        for(int j = 0 ; j< cols ; j++){
            cout << mat[i][j] << " " ; 
        }
        cout << endl ; 
     }

}