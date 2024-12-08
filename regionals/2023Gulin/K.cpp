#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a[185];
map<vector<int>,int> mp;

vector <int> op(vector<int> &a,vector<int> &b){
    vector<int> ret(b.size());
    //cout<<b.size()<<endl;
    for(int i = 0;i<b.size();i++){
        ret[i] = a[b[i]-1];
    }
    return ret;
}
void solve1(){
    //n是个数
    for(int i=1;i<(1<<n);i++){
        vector<int> ans(m);
        for(int j=0;j<m;j++) ans[j]=j+1;
        for(int j=0;j<n;j++){
            if((1<<j)&i){
                ans=op(ans,a[j+1]);
            }
        }
        if(!mp.count(ans)) mp[ans]=1;
    }
    cout<<mp.size()<<endl;
}
void solve2(){
    
    int cnt=0;
    for(int i = 1;i<=n;i++){
    //cout<<mp.size()<<endl;
    map<vector<int>,int> tmp;
        for(auto it : mp){
            vector<int> b = it.first;
            vector<int> res = op(a[i],b);
            tmp[res] = 1;
        }
        for(auto it : tmp){
            vector<int> tt = it.first;
            mp[tt] = 1;
        }
        mp[a[i]] = 1;
    }
    cout<<mp.size()<<endl;
}

void solve(){
    cin>>m>>n;
    int t;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++) {
            cin>>t;
            a[i].push_back(t);
        }
    }
    if(m<=8){
        solve2();
    }
    else solve1();
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
}