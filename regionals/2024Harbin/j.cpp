    #include <bits/stdc++.h>
    using namespace std;
    #define int long long
    const int maxn =2e5 + 10;
    struct chong{
        int dis;
        int x;
        bool operator < (const chong &b) const{
            return dis > b.dis;
        }
    }chg[maxn];
    int a[maxn],ma[maxn];
    vector <int> e[maxn];
    int cnt[maxn];
    signed main(){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--){
            int n,m;
            cin>>n>>m;
            int only = 0;
            for(int i = 1;i<=n;i++) cnt[i] = 0,e[i].clear();//
            for(int i = 1;i<=n;i++){
                cin>>a[i];
                ma[i] = a[i];
                only += a[i];
            }
            map<int,int> mp;
            for(int i = 1;i<=m;i++){
                cin>>chg[i].dis>>chg[i].x;
                e[chg[i].x].push_back(chg[i].dis);
                if(!mp[chg[i].x]){
                    only -= a[chg[i].x];
                    mp[chg[i].x] = 1;
                }
            }
            chg[m+1] = {(int)1e18,0};
            for(int i = 1;i<=n;i++) e[i].push_back((int)1e18);
            priority_queue<chong> q;
            for(int i = 1;i<=n;i++){
                if(mp[i]){
                    q.push({e[i][0],i});
                }
            }
            int di = 0;
            int nxc = 1;
            while(!q.empty()||only){
                while(q.top().dis <= di) q.pop();
                if(q.empty()){
                    if(only + di < chg[nxc].dis){
                        di += only;
                        only = 0;
                    }
                    else{
                        only -= (chg[nxc].dis - di);
                        di = chg[nxc].dis;
                        a[chg[nxc].x] = ma[chg[nxc].x];
                        cnt[chg[nxc].x] ++;
                        q.push({e[chg[nxc].x][cnt[chg[nxc].x]],chg[nxc].x});
                        nxc ++ ;
                    }
                }
                else{
                    int x = q.top().x;
                    if(a[x] + di < chg[nxc].dis){
                        di += a[x];
                        a[x] = 0;
                        if(a[x] == 0) q.pop();
                    }
                    else{
                        a[x] -= (chg[nxc].dis - di);
                        di = chg[nxc].dis;
                        if(a[x] == 0) q.pop();
                        a[chg[nxc].x] = ma[chg[nxc].x];
                        cnt[chg[nxc].x] ++;
                        q.push({e[chg[nxc].x][cnt[chg[nxc].x]],chg[nxc].x});
                        nxc ++ ;
                    }
                    
                }
            }
            cout<<di<<endl; 
        }
        
    }