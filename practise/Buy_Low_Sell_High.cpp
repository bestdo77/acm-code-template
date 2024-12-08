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
    int n;cin>>n;
    priority_queue<int,vector<int>,greater<int>> q;
    int sum=0;
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        if(q.empty()||q.top()>=x){
            q.push(x);
        }else{
            sum+=x-q.top();
            q.pop();
            q.push(x);
            q.push(x);//如果有一个x被选走,相当于选走q.top(),放回x,这样由于已经加上了x-q.top(),所以直接放回x即可
        }
    }
    cout<<sum<<endl;
    return 0;
}