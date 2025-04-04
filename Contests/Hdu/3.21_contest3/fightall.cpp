#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#pragma GCC optimize(3,"Ofast","inline")
#define endl '\n'
#define all(x) x.begin(),x.end()

#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif
inline int read() {
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
    while (c >= '0' && c <= '9') x = x * 10 + (c & 15), c = getchar();
    return x * f;
}

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;

void Atomatic_AC_machine(){
    int n=read(),m=read();
    vector<vector<int>> F(n,vector<int>(m,0)),add(n,vector<int>(m,0));//n个公司，存放着m维
    vector<vector<int>> seq(m,vector<int>(n,0));//m个公司序列，按第m维排序
    vector<i64> hav(m,0);
    for(int i=0;i<m;i++){
        hav[i]=read();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            F[i][j]=read();
        }
        for(int j=0;j<m;j++){
            add[i][j]=read();
        }
    }
    for(int i=0;i<m;i++){
        iota(seq[i].begin(),seq[i].end(),0);
        sort(seq[i].begin(),seq[i].end(),[&](int p,int q){return F[p][i]<F[q][i];});
    }
    vector<int> ok(n,0);//每个公司m维满足的个数
    vector<int> P(m,0);//每个序列目前的指针
    int cnt=0;
    queue<int> candi;
    while(true){//要对每一维能跑的先跑
        for(int i=0;i<m;i++){
            while(P[i]<n&&F[seq[i][P[i]]][i]<=hav[i]){
                ok[seq[i][P[i]]]++;
                if(ok[seq[i][P[i]]]==m){
                    candi.push(seq[i][P[i]]);
                    cnt++;
                }
                P[i]++;
            }
        }
        bool flag=0; 
        while(candi.size()){
            int i=candi.front();
            candi.pop();
            if(ok[i]==m){
                ok[i]++;
                for(int j=0;j<m;j++){
                    hav[j]+=add[i][j];
                }
                flag=1;
            }
        }
        // pa(hav);
        if(cnt==n){
            cout<<"YES"<<endl;
            break;
        }
        if(!flag) {
            cout<<"NO"<<endl;
            break;
        }
    }
}   
signed main(){
    // int size(512<<20);  // 256M
    // __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    t=read();
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}