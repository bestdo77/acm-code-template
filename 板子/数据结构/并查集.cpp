struct Dsu{
    int f[N];
    void init(int n){
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
    }
    int find(int x){
        if(f[x]!=x) return f[x]=find(f[x]);
        return f[x];
    }
    void join(int x,int y,int w){
        int fx=find(x);
        int fy=find(y);
        if(fx!=fy){
            f[fy]=fx;
        }
    }   
}dsu;