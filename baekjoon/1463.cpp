#include <iostream>
using namespace std;

void printArr(int arr[], int size){
    for (int i=1; i<size+1; i++){
        cout << arr[i] << endl;
    }
}

int main(){
    int n, T;
    cin >> T;
    int arr[T+1] = {0};
    for (int i=1; i< T+1; i++){
        //Do I sort here?
        cin >> arr[i]; 
    }

    for (int i=1; i< T+1; i++){
        //Do I sort here?
        if(i == 1){
            continue;
        }
        for (int k=1; k<i+1; k++){
            if (arr[i] < arr[k]){
                int a = arr[k];
                arr[k] = arr[i];
                for (int j=k+1; j<i+1; j++){
                    arr[j+1] = arr[j];    
                }
                arr[k+1] = a;
                break;
            }
        }
    }

    printArr(arr, T);
}