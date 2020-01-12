#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int arr[1001];
    int dp[1001] = {0,};
    int N , ml = 0;
    cin >> N;
    for (int i=1; i<=N; ++i){
        cin >> arr[i];
    }

    dp[0] = 0;
    dp[1] = 1;
    for (int i=1; i<=N; ++i){
        dp[i] =1;

        for (int j=1; j<i; ++j){
            if((arr[i] > arr[j]) && (dp[i] < dp[j]+1)) {
                dp[i] = dp[j] + 1;
            }
        }

        ml = max(ml, dp[i]);
    }

    cout << ml << endl;

    return 0;
}