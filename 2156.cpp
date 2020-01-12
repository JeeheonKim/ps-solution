#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int T; 
    cin >> T;
    int w[T], dp[T];
    for (int i=0; i<T; ++i){
        cin >> w[i];
    }
    dp[0] = w[0];
    dp[1] = w[0]+w[1];
    dp[2] = max(w[1]+w[2], w[0]+w[2]);
    for (int i=3; i<T; ++i){
        dp[i] = max(w[i]+w[i-1]+dp[i-3], dp[i-2]+w[i]);
    } 

    cout << max(dp[T-1], dp[T-2]) << endl;

    return 0;
}