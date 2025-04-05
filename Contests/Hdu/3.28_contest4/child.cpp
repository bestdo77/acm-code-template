#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;

int cnt,id[10][10][10][10];
int ans[N],ok[N],vis[N];
vector<int> in[N],out[N];
void add(int cnt1,int a,int b,int _x,int _y){
    if(a>b){
        swap(a,b);
    }
    int cnt2=id[_x][_y][a][b];
    in[cnt2].push_back(cnt1);
    out[cnt1].push_back(cnt2);
}
void Atomatic_AC_machine(){
    int x,y,_x,_y;
    cin>>x>>y>>_x>>_y;
    if(x>y){
        swap(x,y);
    }
    if(_x>_y){
        swap(_x,_y);
    }
    cout<<ans[id[x][y][_x][_y]]<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    queue<int> q;
    for(int x=0;x<=9;x++){
        for(int y=x;y<=9;y++){
            for(int _x=0;_x<=9;_x++){
                for(int _y=_x;_y<=9;_y++){
                    id[x][y][_x][_y]=++cnt;
                    if(x==0&&y==0){
                        ans[cnt]=1;
                        q.push(cnt);
                    }else if(_x==0&&_y==0){
                        ans[cnt]=2;
                        q.push(cnt);
                    }
                }
            }
        }
    }
    for(int x=0;x<=9;x++){
        for(int y=x;y<=9;y++){
            for(int _x=0;_x<=9;_x++){
                for(int _y=_x;_y<=9;_y++){
                    int cnt1=id[x][y][_x][_y];
                    if(_x){
                        if(x){
                            add(cnt1,(x+_x)%10,y,_x,_y);
                        }
                        if(y){
                            add(cnt1,x,(y+_x)%10,_x,_y);
                        }
                    }
                    if(_y){
                        if(x){
                            add(cnt1,(x+_y)%10,y,_x,_y);
                        }
                        if(y){
                            add(cnt1,x,(y+_y)%10,_x,_y);
                        }
                    }
                }
            }
        }
    }

    while(q.size()){
        int u=q.front();
        q.pop();
        if(ans[u]==1){//必胜态，它所有前继可能有必败态
            for(auto v:in[u]){
                if(ans[v]) continue;
                ok[v]++;
                if(ok[v]==out[v].size()){//必败态所有后继必须是必胜
                    ans[v]=2;
                    q.push(v);
                }
            }
        }else{//必败态，它所有前继都是必胜态
            for(auto v:in[u]){
                if(ans[v]) continue;
                ans[v]=1;
                q.push(v);
            }
        }
    }
    
    
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}