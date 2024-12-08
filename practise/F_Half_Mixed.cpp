#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
int p=0;
void solve(){
    int n,m;cin>>n>>m;
    if((n*(n+1)*m*(m+1)/4)%2==1){
        cout<<"No"<<endl;
        return;
    }
    string s="";
    if((n*(n+1)/2)%2==0){
        cout<<"Yes"<<endl;
        for(int i=p;i>=0;i--){
            if(n>=a[i]){
                n-=i;
                for(int j=1;j<=i;j++){
                    s.push_back(1);
                }
                s.push_back(0);
                n--;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<s<<endl;
        }
    }else if((m*(m+1)/2)%2==0){
         for(int i=p;i>=0;i--){
            if(m>=a[i]){
                m-=i;
                for(int j=1;j<=i;j++){
                    s.push_back(1);
                }
                s.push_back(0);
                m--;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<s[i]<<" ";
            }
            cout<<endl;
        }   
    }else{
        cout<<"No"<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    p=2;
    a[1]=1;
    while(a[p-1]<=1e6){
        a[p]=(p+1)*p/2;
        p++;
    }
    while(t--){
        solve();
    }
    return 0;
}