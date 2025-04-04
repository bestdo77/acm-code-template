#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
// #define __Local__
#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
#endif

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;
map<char,int> mp;
map<int,char> id;
vector<int> e[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    char trump;cin>>trump;
    int nw=3;
    mp[trump]=nw;
    if(trump!='C')mp['C']=--nw;
    if(trump!='D')mp['D']=--nw;
    if(trump!='H')mp['H']=--nw;
    if(trump!='S')mp['S']=--nw;
    id[mp['C']]='C';
    id[mp['D']]='D';
    id[mp['H']]='H';
    id[mp['S']]='S';
    for(int i=0;i<4;i++) e[i].clear();
    for(int i=1;i<=2*n;i++){
        string s;cin>>s;
        e[mp[s[1]]].push_back(s[0]-'0');
    }
    for(int i=0;i<4;i++){
        sort(e[i].begin(),e[i].end());
    }
    vector<pair<string,string>> op;
    for(int i=0;i<4;i++){
        string s1="11";
        string s2="11";
        for(int j=1;j<e[i].size();j+=2){
            s1[1]=s2[1]=id[i];
            s1[0]='0'+e[i][j-1];
            s2[0]='0'+e[i][j];
            op.push_back({s1,s2});
        }
        if(e[i].size()%2){
            if(e[mp[trump]].size()){
                s1[1]=id[i];
                s2[1]=trump;
                s1[0]=e[i].back()+'0';
                s2[0]=e[mp[trump]].back()+'0';
                e[mp[trump]].pop_back();
                op.push_back({s1,s2});
            }else{
                cout<<"IMPOSSIBLE"<<endl;
                return;
            }
        }
    }
    for(auto &[s1,s2]:op){
        cout<<s1<<" "<<s2<<endl;
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}