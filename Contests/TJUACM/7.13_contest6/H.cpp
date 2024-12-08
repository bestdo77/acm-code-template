#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        string s;cin>>s;
        stack<char> sm,bi;
        int cnt=0;
        for(auto it:s){
            if(it=='('||it==')'){
                if(s.front()=='('&&it==')'){
                    sm.pop();cnt++;
                }
                else sm.push(it);
            }
            if(it=='['||it==']'){
                if(s.front()=='['&&it==']'){
                    bi.pop();cnt++;
                }
                else bi.push(it);
            }
            cout<<cnt<<endl;
        }
    }
    return 0;
}