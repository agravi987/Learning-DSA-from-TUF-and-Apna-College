#include<iostream>
using namespace std ; 

// pass by reference demo 
void changeArray(int arr[] , int size){
    for(int i = 0 ; i<size ; i++){
        arr[i] *= 2; 
    }
}

// Linear search demo  , O(N)
int linearSearch(int arr[] , int target){
    int size = sizeof(arr) / sizeof(int) ; 
    for(int i = 0 ; i<size ; i++){
        if(arr[i] == target){
            return i ; 
        }
    }
    return -1 ; 
}


int main () {

    int arr[] = {-1, -4 , 5 , 6,9} ; 

    int smallest = __INT_MAX__ ; 
    int largest = -(__INT_MAX__ - 1 ); 

    int size = sizeof(arr)/sizeof(int) ; 

    for(int i = 0 ; i<size ; i++){
        if(arr[i] < smallest) smallest = arr[i] ; 
        if(arr[i] > largest) largest = arr[i] ; 
    }

    cout << "Smallest number is : " << smallest <<endl ; 
    cout << "Largest number is : " << largest <<endl ; 


    int arr2[] = {1,2,3} ; 
    changeArray(arr2, 3) ;  // Array is always pass by reference 

    for(int i = 0 ; i<3 ; i++){ 
        cout << arr2[i] << " " ; 
    }

    cout << endl ; 

    cout << "-4 exist on index : " << linearSearch(arr , -4) ; 

    return 0 ; 
}