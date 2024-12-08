#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

const int N=1000050;
struct query {
    int l,r,mex;
}q[2000050];

int maxn;
bool cmp(query &x,query &y){
    if(x.l/maxn != y.l/maxn) return x.l < y.l;
    else return x.r < y.r;
}

int arr[N];
map<int,int> mp;
vector <int> a[N];

int tot[N];
int dst;
void add(int x){
    if(!tot[x] ){
        dst ++;
    }
    tot[x] ++;
}
void del(int x){
    if(tot[x] == 1){
        dst--;
    }
    tot[x]--;
}
int res=-998244353;
void MO(int cnt){
    int p1=q[1].l,p2=q[1].r;
    for (int i=p1;i<=p2;i++)add(arr[i]);
    res=max(res,dst-q[1].mex);
    for (int i=2;i<=cnt;i++){
        while (p1>q[i].l)p1--,add(arr[p1]);
        while (p2>q[i].r)del(arr[p2]),p2--;
        while (p1<q[i].l)del(arr[p1]),p1++;
        while (p2<q[i].r)p2++,add(arr[p2]);
        res=max(res,dst-q[i].mex);
    }
}
void solve(){
    int n,m;
    cin >>n>>m;

    for (int i=1;i<=n;i++){
        cin >>arr[i];
        a[arr[i]].push_back(i);
        mp[arr[i]]++;
    }
    int cnt=0;
    for (int i=1;i<=m;i++){
        if (mp[i]){
            //cout <<i<<":";
            if (a[i][0]>1)q[++cnt]={1,a[i][0]-1,i};
            else {
                if (i==1)res=max(res,-1);
                else res=max(res,0);
            }
            for (int j=0;j<a[i].size()-1;j++){
                //cout <<a[i][j]<<" ";
                if (a[i][j+1]-1<a[i][j]+1){
                    if (i==1)res=max(res,-1);
                    else res=max(res,0);
                };
                q[++cnt]={a[i][j]+1,a[i][j+1]-1,i};
            }
            //cout <<endl;
            if (a[i][a[i].size()-1]<n)q[++cnt]={a[i][a[i].size()-1]+1,n,i};
            else {
                if (i==1)res=max(res,-1);
                else res=max(res,0);
            }
        }else {
            q[++cnt]={1,n,i};
            break;
        }
        if (i==m){
            q[++cnt]={1,n,i+1};
        }
    }
    // int front[500010];
    // for(int i = 1;i<=n;i++){
    //     if(front[i]){
    //         int l = front[i] + 1;
    //         int r = i-1;
    //         if(l>r){
    //             if(arr[i] == 1) res = max(res,-1);
    //             else res = max(res,0);
    //         }
    //         else{
    //             q[++cnt] = {l,r,arr[i]};
    //         }
    //     }
    // }
    //特判
    maxn = sqrt(cnt);
    int flag = 1;
    for(int i = 1;i<=n;i++){
        if(arr[i] != 1) {flag = 0;break;} 
    }
    if(flag){
        cout<<-1<<endl;
        return;
    }

    sort(q+1,q+1+cnt,cmp);
    MO(cnt);

    for (auto it:mp){
        a[it.first].clear();
    }
    mp.clear();

    cout<<res<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--){
        solve();
    }
}