#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
const int element=3;
int a[N];
void solve(){
    string s;cin>>s;
    int st3=0,st5=0;
    char last='0';
    int len=s.length();
    s=" "+s;
    for(int i=1;i<=len;i++){
        if(s[i]=='3'||s[i]=='4'){
            st5++;    
            if(s[i]!='4') st3++;
            else st3=0;
            if(st3>=10){
                cout<<"invalid"<<endl;
                return;
            }
            if(st5>=90){
                cout<<"invalid"<<endl;
                return;
            }
        }else{
            st3=0;
            st5=0;
            if(s[i]=='5'&&last=='5'){
                cout<<"invalid"<<endl;
                return;
            }
            last=s[i];
        }
    }
    
    cout<<"valid"<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}