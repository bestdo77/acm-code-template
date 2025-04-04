#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
const int N=1e6+10;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
int a[N],b[N],c[N];
signed main(){
    int n,k;cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    sort(a+1,a+1+n,greater<int>());
    sort(b+1,b+1+n,greater<int>());
    sort(c+1,c+1+n,greater<int>());
    vector<int> ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=min(k/i,n);j++){
            for(int p=1;p<=min(k/(i*j),n);p++){
                ans.emplace_back(a[i]*b[j]+b[j]*c[p]+c[p]*a[i]);
            }
        }
    }
    nth_element(ans.begin(),ans.begin()+k-1,ans.end(),greater<int>());
    cout<<ans[k-1]<<endl;
    return 0;
}