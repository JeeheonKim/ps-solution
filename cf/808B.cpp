#include <iostream>
#include <iomanip> // for std::setprecision()
using namespace std;
int db(int a, int b){
    cout << a << " * " << b <<'\n';
}
int main(){
    float n, k; float t[200000];
    float ss, st, ans;
    cin >> n >> k; 
    int sub = 0;
    for (int i=0; i<n; ++i){
        cin >> t[i];
        ss += t[i];
        if (i<k-1) { db(k-1-i, t[i]); sub += (k-1-i)*t[i];} //until '4'
        else if( (n-k-1) < i) { db(i-n+k+1, t[i]); sub+= t[i]*(i-n+k+1);}
    }

    ans = (k*ss - sub)/(n-k+1);
    cout << fixed << setprecision(16) <<  ans << '\n';
} 


// 19 3  20 16 14 10 1  13 7  3
//    19 3  20 16 14 10 1  13 7  3
//       19 3  20 16 14 10 1  13 7  3
//          19 3  20 16 14 10 1  13 7  3
//             19 3  20 16 14 10 1  13 7  3
//                19 3  20 16 14 10 1  13 7  3

// 10-6-1 3

// 8  16 2  13 15 9  5  13 9  2
//    8  16 2  13 15 9  5  13 9  2
//       8  16 2  13 15 9  5  13 9  2
//          8  16 2  13 15 9  5  13 9  2
//             8  16 2  13 15 9  5  13 9  2
//                8  16 2  13 15 9  5  13 9  2
//                   8  16 2  13 15 9  5  13 9  2


// 3 4 7
//   3 4 7