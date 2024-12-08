#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+10;
int Log[maxn];
int st[maxn][20];//n logn + 1

void init(int n){
    for(int i = 2;i < maxn;i++) Log[i] = Log[i>>1] + 1;
    
    for(int j = 1;j <= Log[n] + 1;j++){
        for(int i = 1;i + (1 << j) - 1 <= n;i++){
            st[i][j] = max(st[i][j-1],st[i + (1 << j-1)][j-1]);
        }
    }
}

int query(int l,int r){
    int k = Log[r - l + 1];
    return max(st[l][k],st[r - (1<<k) + 1][k]);
}
