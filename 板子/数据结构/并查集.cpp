#include <bits/stdc++.h>
using namespace std;
struct Dsu{
    vector<int> f,rk;
    Dsu(int n){
        f.assign(n+1,0);
        rk.assign(n+1,1);
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
    };
    int find(int x){
        if(f[x]!=x) return f[x]=find(f[x]);
        return f[x];
    }
    void join(int x,int y){
        int fx=find(x);
        int fy=find(y);
        if (fx!=fy) {
            if (rk[fx]<rk[fy]) {
                swap(fx,fy);
            }
            f[fy]=fx;
            rk[fx]+=rk[fy];
        }
    }   
};
int main(){
    int n,m;cin>>n>>m;
    Dsu dsu(n);
    for(int i=1;i<=m;i++){
        int op,l,r;cin>>op>>l>>r;
        if(op==1){
            dsu.join(l,r);
        }else{
            if(dsu.find(l)==dsu.find(r)){
                cout<<"Y"<<endl;
            }else{
                cout<<"N"<<endl;
            }
        }
    }
    return 0;
}

