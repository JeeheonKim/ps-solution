#include <iostream>
#include <string>
using namespace std;

int main(){
    int N;
    string ss;
    int l = 0;
    int r = 0;
    cin >> N;
    cin >> ss;
    
    for (int i=0; i<N; ++i){
        if (ss[i] == 'L'){
            l++;
        }    
    }
    r = N - l;

    cout <<  l+r+1 << endl;
}