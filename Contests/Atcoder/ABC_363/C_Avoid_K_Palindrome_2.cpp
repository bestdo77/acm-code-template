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
unordered_map<string,int> mp;
bool isPall(string s){
    // cout<<s<<endl;
    int l=0,r=s.length()-1;
    while(l<=r){
        if(s[l]!=s[r]) return 0;
        l++,r--;
    }
    return 1;
}
bool judge(string s,int k){
    for(int i=0;i<s.length()-k+1;i++){
        if(isPall(s.substr(i,k))) return 0;
    }
    return 1;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,k;cin>>n>>k;
    string s;cin>>s;
    for(int i=1;i<=n;i++){
        a.push_back(i);
    }
    map<char,int> mp1;
    for(auto it:s) mp1[it]++;
    bool flag=1;
    for(auto it:mp1){
        if(it.second>=2) flag=0;
    }
    if(flag){
        if(k==1){
            cout<<0<<endl;
            return 0;
        }
        int ans=1;
        for(int i=1;i<=n;i++){
            ans*=i;
        }
        cout<<ans<<endl;
        return 0;
    }

    int ans=0;
    sort(s.begin(),s.end());
    do{
        if(mp[s]) continue;
        mp[s]=1;
        // cout<<tmp<<endl;
        if(judge(s,k)){
            // cout<<tmp<<endl;
            ans++;
        }
    }while(next_permutation(s.begin(),s.end()));
    cout<<ans<<endl;
    return 0;
}