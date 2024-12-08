#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int MAXN=1e3+10;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int t;cin>>t;
    while(t--){
        int a,b;cin>>a>>b;//a0,b1;
        for(int i=1;i<=(a+b);i++){
            if(i%2==0){
                if(a){
                    cout<<'1';
                    a--;
                }else{
                    cout<<'0';
                    b--;
                }
            }else{
                if(b){
                    cout<<'1';
                    b--;
                }else{
                    cout<<'0';
                    a--;
                }
            }
        }
        cout<<endl;
    }
    return 0;
}