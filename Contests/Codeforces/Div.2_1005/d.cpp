#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}

int msb(int x){
    if(x==0) return 0;
    return (int)log2(x);
}
int a[N];
int pos[33][N];
int sumxor[N];
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    reverse(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sumxor[i]=0;
    }
    for(int i=1;i<=n;i++){
        sumxor[i]=sumxor[i-1]^a[i];
    }
    for(int i=1;i<=n+1;i++){
        for(int j=0;j<=32;j++){
            pos[j][i]=0;
        }
    }
    for(int i=n;i>=0;i--){
        for(int j=0;j<=32;j++){
            if(msb(a[i])==j){
                pos[j][i]=i;
            }else{
                pos[j][i]=pos[j][i+1];
            }
        }
    }
    // for(int j=0;j<=32;j++){
    //     for(int i=1;i<=n;i++){
    //         db(pos[j][i])
    //     }
    //     cendl
    // }
    // cendl
    for(int i=1;i<=q;i++){
        int x;cin>>x;
        int p=0;
        while(p<=n){
            int bx=msb(x);
            int p1=inf;
            for(int j=bx;j<=32;j++){
                if(pos[j][p+1]) {
                    p1=min(pos[j][p+1],p1);
                }
            }
            // db(i<<" "<<bx<<" "<<p<<" "<<p1)
            // cendl
            if(p1==inf){
                p=n;break;
            }else{
                x^=sumxor[p];
                x^=sumxor[p1-1];
                p=p1-1;
                if(x>=a[p1]) p++,x^=a[p1];
                else break;
            }
        }
        cout<<p<<" ";
    }        
    cout<<endl;
}   
signed main(){
    auto begin = std::chrono::high_resolution_clock::now();
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        cerr << "Case #" << ++i << ": "<<endl;
        Atomatic_AC_machine();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n";
    return 0;
}