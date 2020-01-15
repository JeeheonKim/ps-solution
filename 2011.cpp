#include <iostream>
#include <string>
using namespace std;
#define c 100000

int lastTwo(int a, int b){
    int d = (a*10)+b;
    if (a==0) return 0;
    if (d <= 26 &&  d!=0) 
        return 1;
    return 0;
}

int lastOne(int a){
    if (a==0) return 0;
    return 1;
}

int main() {
    int p[5001];  
    int ret; string tmp;
    int dp[5001];
    
    cin >> tmp;
    int l = tmp.length();

    for (int i=1; i<=l; ++i){
        p[i] = tmp[i-1] -'0';
    }

    dp[1] = (p[1] == 0) ? 0 : 1;
    if (dp[1] == 0) {cout << 0 << '\n'; return 0;}
    dp[2] = lastTwo(p[1], p[2]) ? 2 : 1;
    
    int a = 0, b = 0;

    for (int i=3; i<=l; ++i) {   
        dp[i] = ((dp[i-1] * lastOne(p[i])) + (dp[i-2] * lastTwo(p[i-1], p[i])))%c;
            cout << dp[i] << '\n';

    }

    cout << dp[l] << '\n';

}

//1012