#include <bits/stdc++.h>
using namespace std;

const int maxn = 50;
int deg[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 1;i<n;i++){
        int u,v;
        cin>>u>>v;
        deg[u] ++;
        deg[v] ++;
    }
    int bu = 0;
    for(int i = 1;i<=n;i++){
        if(deg[i]!=1) bu++;
    }
    if(bu==0||bu==1){
        cout<<"Bob";
        return 0;
    }
    if(!(bu&1)){
        cout<<"Alice";
    }
    else cout<<"Bob";
}