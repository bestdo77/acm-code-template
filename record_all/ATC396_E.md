- 给定一张无向带权图，要求构造元素和最小的数组a, 使得a[u]^a[v]=w;
- 看见异或想到按位拆分，就很明晰了，对于连通但是w=0的点，要求这一位相同，w=1的点，要求这一位相反。
- **当异或问题按位拆分之后，问题独立或者可以贪心，则总是应该想到按位拆分**
- 在此基础上染色，对于每个连通块，如果染色失败就说明无解，染色成功则要求构造1最小的解。
- 代码实现还有若干细节：
  - 没必要去真的涂一次1，涂一次0，可以记录01的数量然反转涂。
  - 对于每个连通块可以用一个vector存，每次清就行了，很聪明的做法。
```cpp
struct edge{
    int v,same;
};
vector<edge> e[32][N];
int ans[N];
int col[N];
vector<int> cur;
int cnt[2];
void dfs(int bit,int u,int c){
    cur.push_back(u);
    col[u]=c;
    cnt[c]++;
    for(auto [v,same]:e[bit][u]){
        if(col[v]!=-1){
            if(col[v]!=c^same){
                cout<<-1<<endl;
                exit(0);
            }
            continue;
        }
        dfs(bit,v,c^same);
    }
}
void Atomatic_AC_machine(){
    int n,m;cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,w;cin>>u>>v>>w;
        for(int j=0;j<32;j++){
            if(w&(1ll<<j)){
                e[j][u].push_back({v,1});
                e[j][v].push_back({u,1});
            }else{
                e[j][u].push_back({v,0});
                e[j][v].push_back({u,0});
            }
        }
    }

    for(int bit=0;bit<32;bit++){
        for(int i=1;i<=n;i++){
            col[i]=-1;
        }
        for(int i=1;i<=n;i++){
            if(col[i]==-1){
                cnt[0]=cnt[1]=0;
                cur.clear();
                dfs(bit,i,0);
                if(cnt[0]>cnt[1]){
                    for(auto u:cur){
                        ans[u]+=(col[u]==0) ? 0 : (1ll<<bit);
                    }
                }else{
                    for(auto u:cur){
                        ans[u]+=(col[u]==0) ? (1ll<<bit) : 0;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
```