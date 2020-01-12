#include <iostream>
#include <string>
using namespace std;
int max(int a, int b){
    if (a > b) return a;
    else return b;
}

int main(){
    string verdict = "NO";
    long long T = 0; long long N = 0; long long until = 0;
    long long Y = 0;
    cin >> T;
    //n types
    // tastiness : -1 , 0 , 1
    
    for (int i=0; i<T; ++i){
        Y = 0;
        cin >> N;
        long long tastes[N];

        for (int j=0; j<N; ++j){
            cin >> tastes[j];
            Y += tastes[j];
        }
        // find the max of Adel
        int mm = 0;

        for (int a=0; a<N; ++a){
            until = 0;
            for (int b=a;  b<N; ++b){
                if (a==0 && b==N-1) continue;
                until += tastes[b];
                mm = max(mm, until);

            }
        }
        if (mm < Y) verdict = "YES";
        else verdict = "NO";

        cout << verdict << '\n';


    }
    //output: YES if Yasser buys > Adel (regardless of Adels)

    
}