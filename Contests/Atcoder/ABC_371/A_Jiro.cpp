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
// int a[N];
vector<int> G[N];
void Atomatic_AC_machine(){
    char ab,ac,bc;cin>>ab>>ac>>bc;
    if(ab=='>'&&ac=='>'&&bc=='>') cout<<"B"<<endl;
    else if(ab=='>'&&ac=='>'&&bc=='<') cout<<"C"<<endl;
    else if(ab=='>'&&ac=='<'&&bc=='>') cout<<"A"<<endl;
    else if(ab=='>'&&ac=='<'&&bc=='<') cout<<"A"<<endl;
    else if(ab=='<'&&ac=='>'&&bc=='>') cout<<"A"<<endl;
    else if(ab=='<'&&ac=='>'&&bc=='<') cout<<"B"<<endl;
    else if(ab=='<'&&ac=='<'&&bc=='>') cout<<"C"<<endl;
    else cout<<"B"<<endl;
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