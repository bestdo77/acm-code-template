#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
vector<int> a;
vector<array<int,element>> v;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        string s1,s2;cin>>s1>>s2;
        queue<int> q;
        for(int i=1;i<=n;i++){
            string s3,s4;cin>>s3>>s4;
            if(s1.find(s3)!=string::npos&&s4.find(s2)!=string::npos){
                // cout<<i;
                q.push(i);
            }
        }
        while(!q.empty()){
            int x=q.front();q.pop();
            cout<<x;
            if(!q.empty())cout<<" ";
        }
        cout<<endl;
    }
    return 0;
}