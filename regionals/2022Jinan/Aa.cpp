#include <bits/stdc++.h>
#define int long long
#define endl '\n'
#define pii pair<int,int>
using namespace std;
int a[510],ans[510];
int e[510];
int n,m;
struct node{
    int pos,val;
    bool operator < (const node a)const{
        return val<a.val;
    }
}ee[510];
void solve(){
    cin>>n>>m;
    priority_queue<pii> q;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        ans[i] = 0;
        q.push(make_pair(a[i],i));
    }
    int cnt = 0;
    int res = 1e17;
    
    int l = 1,r = q.top().first;
        while(l<=r){
            int mid = l+r>>1;
            int down=0,up = 0,on = 0;
            int t = 0;
            for(int i = 1;i<=n;i++){
                if(a[i] < mid) down ++;
                else if(a[i] > mid) up++;
                else on++;
                ee[i].val = abs(a[i]-mid) + ans[i];
                ee[i].pos = i;
                t+=abs(a[i]-mid) + ans[i];
            }
            sort(ee+1,ee+1+n);
            for(int i = n;i>0&&i>n-m;i--){
                t -=ee[i].val;
                if(a[ee[i].pos]>mid) up--;
                else if(a[ee[i].pos]<mid) down--;
                else on--;
            }
            if(t<res) res = t;
            if(up<down){
                if(up+on<down){
                    r=mid-1;
                }
                else break;
            }
            else if(down<up){
                if(down+on<up){
                    l = mid+1;
                }
                else break;
            }
            else break;
        }
    
    while(!q.empty()){
        int pos = q.top().second;
        int val = q.top().first;
        q.pop();
        if(val == 1) break;
        val /= 2;
        a[pos] = val;
        cnt ++;
        q.push(make_pair(val,pos));
        ans[pos] ++ ;
        int l = 1,r = q.top().first;
        while(l<=r){
            int mid = l+r>>1;
            int down=0,up = 0,on = 0;
            int t = 0;
            for(int i = 1;i<=n;i++){
                if(a[i] < mid) down ++;
                else if(a[i] > mid) up++;
                else on++;
                ee[i].val = abs(a[i]-mid) + ans[i];
                ee[i].pos = i;
                t+=abs(a[i]-mid) + ans[i];
            }
            sort(ee+1,ee+1+n);
            for(int i = n;i>0&&i>n-m;i--){
                t -=ee[i].val;
                if(a[ee[i].pos]>mid) up--;
                else if(a[ee[i].pos]<mid) down--;
                else on--;
            }
            if(t<res) res = t;
            if(up<down){
                if(up+on<down){
                    r=mid-1;
                }
                else break;
            }
            else if(down<up){
                if(down+on<up){
                    l = mid+1;
                }
                else break;
            }
            else break;
        }
    }
    cout<<res<<endl;

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}