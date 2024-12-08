#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
struct node{
    int x,y;
};
bool cmp(node a,node b){
    return min(a.x,b.y)<min(a.y,b.x);
}
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n=1;
    while(cin>>n&&n){
        vector<node> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].x>>a[i].y;
        }
        sort(a.begin(),a.end(),cmp);
        // for(int i=0;i<n;i++){
        //     cout<<a[i].x<<a[i].y<<endl;
        // }
        int cost1=0,cost2=0;
        for(int i=0;i<n;i++){
            cost1+=a[i].x;
            cost2=max(cost1+a[i].y,cost2+a[i].y);
        }
        cout<<cost2<<endl;     
   }
    return 0;
}