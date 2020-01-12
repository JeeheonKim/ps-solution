#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;
int pow(int a, int exp){
    int ret = 1;
    for (int i=0; i<exp; ++i){
        ret *= a;
    }
    return ret;
}
int main(){
    string N; long long int ss = 0;

    cin >> N;

    
    int digit = N.length();    
    vector<int> n;

    for (int i=0; i<digit; ++i){
        n.push_back(N[i]-'0');
    }

    n.resize(digit);

    std::sort(n.begin(), n.end());

    for (int i=0; i<digit; ++i){
        ss += n[i];
    } 

    if (ss %3 == 0 && n[0] == 0){
        for (int i=digit-1; i>0; --i){
            cout << n[i];
        }            
        cout << 0 <<'\n';
    } else {
        cout << -1 << endl;
    }
    return 0;
}