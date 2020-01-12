//Greedy
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N, K;
    int arr[11];

    cin >> N >> K;
    for (int i=1; i<=N; ++i){
        cin >> arr[i];
    }

    // fit the largest possible coin and then is if it's possible
    int leftover = K;
    int mn = 0;
        for(int i=N;i>=1; i--){
            if(leftover == 0){
                break;
            }
            if (arr[i] <=K){
                mn+=(leftover/arr[i]);
                leftover= leftover % arr[i];
            }
        }
    

    cout << mn << '\n';
        
}