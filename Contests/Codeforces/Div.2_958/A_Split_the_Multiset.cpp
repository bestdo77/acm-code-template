#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        priority_queue<int,vector<int>,greater<int> > q;
        int cnt=0;
        while(!q.empty()) q.pop();
        for(int i=1;i<=n;i++){
            q.push(1LL);
        }
        int cnt1=0;
        int sum=0;
        while(q.size()>1){
            sum+=q.top();
            q.pop();
            cnt1++;
            if(cnt1==m){
                q.push(sum);
                sum=0;
                cnt1=0;
                cnt++;
            }
            // cout<<q.top()<<endl<<endl;    
            
        }
        if(cnt1) cnt++;
        cout<<cnt<<endl;
    }
    return 0;
}