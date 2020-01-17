#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N; long long mm;
    int arr[1001]; long long dp[1001];

    cin >> N;
    for (int i=1; i<=N; ++i){
        cin >> arr[i];
    }

    for (int i=1; i<=N; ++i){
        dp[i] =arr[i];
        for (int j=1; j<N; ++j){
            if(dp[i]< dp[j]+arr[i] && arr[i]>arr[j]){
                //dp[i] = max(dp[i], dp[j]+arr[i]);
                dp[i] = (dp[i]> dp[j]+arr[i])? dp[i] : dp[j]+arr[i];
            }
        }
        mm = (dp[i]>mm)? dp[i]:mm;
    }

    cout << mm << endl;
}