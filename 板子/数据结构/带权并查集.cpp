/*pos[a]=pos[b]+d,找区间的题*/
int pos[N];
struct Dsu{
    vector<int> f,rk;
    Dsu(int n){
        f.assign(n+1,0);
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
    };
    int find(int x){
        if(f[x]!=x) {
            int fx=find(f[x]);
            pos[x]+=pos[f[x]];
            f[x]=fx;
            return fx;
        }
        return f[x];
    }
    void join(int x,int y,int d){
        int fx=find(x);
        int fy=find(y);
        if (fx!=fy) {
            f[fx]=fy;
            pos[fx]=pos[y]-pos[x]+d;
        }else{
            if(pos[x]-pos[y]!=d) flag=0;
        }
    }   
};