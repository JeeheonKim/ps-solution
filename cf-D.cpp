#include <iostream>
using namespace std;
int max(int a, int b){
    if (a>b) return a;
    else return b;
}
int main(){
    unsigned int N, mm;
    unsigned int ones = 0;
    cin >> N;
    unsigned int arr[N];
    for (int i=0; i<N; ++i){
        cin >> arr[i];
        ones = ones | arr[i];
    }

    int length = 0;
    while(ones != 0){
        ones = ones >> 1;
        length++;
    }
    //check each digit and ask if ones are more than half
    // if the number is smaller than the digit than..

    unsigned int ret = 0;
    unsigned int nums = 0; //count ones
    unsigned int p;
    unsigned int cnt = length;
    while (cnt != 0){
        unsigned int msk = 1 << (cnt -1);

        for (int i=0; i<N; ++i){
            if ((msk & arr[i])== 1){

                nums ++;
                cout << "mask"<< msk << "arr[i]" << arr[i]<< endl;

            }

        }

        cout << "nums"<< nums << endl;
        if (nums >= N-nums){
            ret += (1 << (length-1));
        }

        cnt --;
    }

    int out = 0;
    for (int i=0; i<N; ++i){
       out = max(ret^arr[i], out);
    }


    cout << out << endl;

}