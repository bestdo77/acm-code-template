#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int N=1e6+10;
int a[N],b[N];
bool cmp(int x,int y){
    return x>y;
}
multiset<int> s,o;
vector<int> ans;
void solve(){
    ans.clear();
    s.clear();
    o.clear();
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+m,cmp);
    int les=n-m;
    for(int i=1;i<=m;i++){
        if(a[i]>b[i]) goto end;
        les-=b[i]-a[i];
    }
    if(les<0) goto end;
    for(int i=1;i<=n;i++) s.insert(a[i]);
    for(int i=1;i<=m;i++){
        for(int j=a[i];j<b[i];j++){
            o.insert(j);//必须要有的元素
        }
    }
    while(les){
        int v=*s.begin();
        ans.push_back(v);
        s.erase(s.begin());
        s.insert(v+1);
        s.erase(s.begin());
        if(o.find(v)!=o.end()) o.erase(o.find(v));
        else{
            les--;//算冗余的元素
            if(v==b[m]) goto end;
        }
    }
    cout<<ans.size()+o.size()<<endl;
    for(auto i:ans){
        cout<<i<<" ";
    }
    for(auto i:o){
        cout<<i<<" ";
    }cout<<endl;
    return;
    end:
        cout<<-1<<endl;
        return;
}
int main(){
    // cout<<sqrt(200000)<<endl; 
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // cout<<(1<<2+1)<<endl;
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
}