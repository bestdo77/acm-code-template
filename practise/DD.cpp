#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include<cmath>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn=1e6+500;
ll aa[maxn],bb[maxn],cc[maxn];
void findYinzi(){
	for (ll i=1;i<=1e6;i++){
		for (ll j=1;j*i<=1e6;j++){
			aa[i*j]++;
		}
	}
}
void solve(){
	int t;
	cin>>t;
	while (t--){
		int n;
        cin>>n;
		for (int i = 1;i <= n;i++){
            cin>>aa[i];
        }
        for (int i = 1;i <= n*n ;i++){
            for (int j = 1; j <= n-1 ;j++){
                while (aa[j]<aa[j+1]){
                    aa[j]++;
                    aa[j+1]--;
                }
            }
        }
        ll ans = 1;
        for (int i = 1;i <= n;i++){
            ans = ans * aa[i] % 998244353;
        }
        cout<<ans<<endl;
	}
}
int main(){
	solve();
	return 0;
}
