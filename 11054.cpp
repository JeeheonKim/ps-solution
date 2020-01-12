#include <iostream>

using namespace std;

int arr[1001];
int dp[2][1001];
int N = 0; //input

void maxDec(){
    for (int i=N; i>=1; i--){
        int mm = 1;
        for (int j=i+1; j<=N; ++j){
            if (arr[i] > arr[j] && mm <= dp[1][j]){
                mm = dp[1][j]+1;
            }
        }
        dp[1][i] = mm;
    }
}

void maxInc(){
    for (int i=1; i<=N; i++){
        int mm = 1;
        for (int j=1; j<i; ++j){
            if (arr[i] > arr[j] && mm <= dp[0][j]){
                mm = dp[0][j]+1;
            }
        }
        dp[0][i] = mm;
    }
}

int main(){
    int mm = 0;
    cin >> N;
    for (int i=0; i<N; ++i){
        cin >> arr[i];
    }

    for (int i=1; i<=N; ++i){
        dp[0][i] = 1;
        dp[1][i] = 1;
    }

    maxInc(); maxDec();

    for (int i=1; i<=N; ++i){
        mm = max(mm, (dp[0][i]+dp[1][i]-1));      
    }

    cout << mm << '\n';

    return 0;
}

