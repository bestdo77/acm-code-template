#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int a[N];
int b[N];
#define pii pair<int,int> 
void solve(){
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    vector<pii> ans;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            for(int j=n;j>=i;j--){
                if(a[j]<a[i]){
                    sort(a+i,a+j+1);
                    cnt++;
                    ans.push_back({i,j});
                    break;
                }
            }
        }
    }
    
    cout<<cnt<<endl;
    for(auto it:ans){
        cout<<it.first<<" "<<it.second<<endl;
    }
}
int main(){
    int t;cin>>t;
    while(t--){
        solve();
    }
}