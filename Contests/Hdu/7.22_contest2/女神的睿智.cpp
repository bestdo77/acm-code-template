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
        map<char,int> mp;
        string s;cin>>s;
        for(auto it:s){
            mp[it]++;
        }
        string s1="";
        for(int i=0;i<s.length();i+=2){
            s1+=s[i];
        }
        // cout<<s1<<endl;
        string s2="";
        for(int i=0;i<s.length();i+=2){
            s2+=s1[i];
        }
        // cout<<s2<<endl;
        if(s2[0]==s2[1]){
            cout<<s2[0]<<endl;
            continue;
        }
            if(mp[s2[0]]==mp[s2[1]]){
                cout<<"N"<<endl;
            }else if(mp[s2[0]]>mp[s2[1]]){
                cout<<s2[0]<<endl;
            }else{
                cout<<s2[1]<<endl;
            }
            mp.clear();
    }
    return 0;
}