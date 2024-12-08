#include <bits/stdc++.h>
using namespace std;
#define i64 long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
const int element=3;
int a[N];
vector<int> G[N];
multiset<int> q1;
multiset<int,greater<int>> q2;
int len;
void restruct(){
    int k=(len/2)+1;
    while(q2.size()>k) q1.insert(*q2.rbegin()),q2.erase(--q2.rbegin().base());
	while(q2.size()<k) q2.insert(*q1.rbegin()),q1.erase(--q1.rbegin().base());
}
void insert(int x){
    len++;
    if(q2.empty()||x>=*q2.rbegin()) q2.insert(x);
    else q1.insert(x);
    restruct();
}
int qmid(){
    return *q2.rbegin();
}
void del(int x){
    len--;
    auto l=q1.lower_bound(x);
    auto r=q2.lower_bound(x);
    if(l!=q1.end()){
        q1.erase(l);
    }else if(r!=q2.end()){
        q2.erase(r);
    }else{
        assert(0);
    }
    restruct();
}
void clear(){
    len=0;
    q1.clear();
    q2.clear();
}
void Atomatic_AC_machine(){
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}