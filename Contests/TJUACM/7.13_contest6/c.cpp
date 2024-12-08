#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a1[26];
int a2[26];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        string s1,s2;cin>>s1>>s2;
        for(auto it:s1){
            a1[it-'a']++;
        }
        for(auto it:s2){
            a2[it-'a']++;
        }
        bool flag=1;
        for(int i=0;i<26;i++){
            if(a1[i]-a2[i]%k==0){
                a1[i+1]+=(a1[i]-a2[i])/k;
            }else{
                flag=0;break;
            }
        }
        if(a1[25]!=a2[25]) flag=0;
        if(flag) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}