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
struct Trie
{
    #define lson(now) tree[now][0]
    #define rson(now) tree[now][1]

    int tree[N * 40 + 5][2], sum[N * 40 + 5], root[N + 5], total;

    void Clear ()
    {
        lson(0) = rson(0) = sum[0] = 0;
        root[0] = total = 0;
        return;
    }

    int Insert ( int pre, int x, int bit )
    {   
        int now = ++total;
        lson(now) = lson(pre);
        rson(now) = rson(pre);
        sum[now] = sum[pre];
        ++sum[now];

        if ( bit == -1 )
            return now;

        if ( (x >> bit) & 1 )
            rson(now) = Insert(rson(pre), x, bit - 1);
        else
            lson(now) = Insert(lson(pre), x, bit - 1);
        return now;
    }

    void Insert ( int pos, int x )
    {
        root[pos] = Insert(root[pos - 1], x, 30);
        return;
    }

    int Query ( int x, int y, int bit, int val )
    {
        if ( bit == -1 )
            return 0;
        
        if ( (val >> bit) & 1 )
        {
            if ( sum[lson(y)] - sum[lson(x)] )
                return Query(lson(x), lson(y), bit - 1, val) ^ (1 << bit);
            return Query(rson(x), rson(y), bit - 1, val);
        }

        if ( sum[rson(y)] - sum[rson(x)] )
            return Query(rson(x), rson(y), bit - 1, val) ^ (1 << bit);
        return Query(lson(x), lson(y), bit - 1, val);
    }

    int Query ( int L, int R, int val )
    {
        return Query(root[L - 1], root[R], 30, val);
    }
}Tree;
void Atomatic_AC_machine(){
    Tree.Clear();
    int n,k;cin>>n>>k;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[i]=x;
        Tree.Insert(i,x);
    }
    int ans=inf;
    for(int i=1;i<=n;i++){
        int l=i-1,r=n+1;
        while(l+1<r){
            int mid=l+r>>1;
            if(Tree.Query(i,mid,a[i])>=k){
                r=mid;
            }else{
                l=mid;
            }
            if(r!=n+1){
                ans=min(r-i+1,ans);
            }
        }
    }
    if(ans==inf) cout<<-1<<endl;
    else cout<<ans<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}