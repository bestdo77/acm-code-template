#include<bits/stdc++.h>
using namespace std;
#define C cout
int main() {
	
	int T;cin>>T;
	while (T --) {
		int n ,m;cin>>n>>m;
		int x = n - m - 2;
		if (x <= 0) {
			C<<-1<<endl;
			continue;
		}
		int r = x / 3 * 2 + x % 3;
		int l = 1;
		int p = n - x / 3 + 1;
		for(int i = r + 1;i < p;++ i) C<<i<<" ";
		for(int i = 1;i <= x / 3;++ i) {
			C<<l++<<" "<<r--<<" "<<p++<<" ";
		}
		for(int i = l;i <= r;++ i) C<<i<<" \n"[i==r];

	}
	
	return 0;
}
