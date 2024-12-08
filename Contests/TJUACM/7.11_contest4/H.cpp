#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
const int MAXN=2e4;
unordered_map<string,pair<int,int>[MAXN]> maps;//存储每科作业
unordered_map<string,int> cnt;//每科作业的个数
unordered_map<string,pair<int,int>> st;//存储每科作业的及格最短时间和值
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++){
            string s;cin>>s;
        }
        int m;cin>>m;
        for(int i=1;i<=m;i++){
            string s;cin>>s;
            int val,time;cin>>val>>time;
            maps[s][++cnt[s]]={val,time};
        }
        int time,p;cin>>time>>p;
        //对每科作业进行二分查找，查找及格最短时间，对时间进行查询，然后看当前时间的背包
        for(auto it:maps){
            int l=-1,r=101;
            while(l+1<r){
                int mid=(l+r)>>1;
            }
            st[it.first].first=r;//记录最短时间
        }
    }
    return 0;
}