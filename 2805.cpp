#include <iostream>
using namespace std;
#define ll long long

ll l[1000000];
//binary search
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll N, K;
	cin >> K >> N;

	ll temp=0, max=0;
	for (int i=0; i<K; ++i) {
		cin >> temp;
		l[i] = temp;
		if (max < temp)
			max = temp;
	}
	
	ll left =0, right=max;
	ll mid = max/2;
	ll total =0, result =0; 

	while (left <= right){
		total = 0;
		mid = (left+right)/2;

		for (int i=0; i<K; ++i){
			if (l[i] > mid)
				total+= (l[i]-mid);	
		}

		if (total>=N) {
			if(result <= mid)
				result = mid;
//			if (total == N) break;	
			left = mid+1;
		}
		else if (total<N) {
			right = mid-1;
		}
	}
		
	cout << mid << '\n';
		
	return 0;
	
}

