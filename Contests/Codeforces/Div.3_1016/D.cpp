#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int, int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(), x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

int c[2][2]={{0,3},{2,1}};
void Automatic_AC_machine() {
    // db(c[0][0])
    // cendl
    int n, m;
    cin >> n >> m;
    while (m--) {
        string op;
        cin >> op;
        if (op == "->") {
            i64 x, y;
            cin >> x >> y;
            --x,--y;
            i64 ans=0;
            for(int i=0;i<n;i++){
                i64 cur=(1ll<<(2*i)); 
                ans+=cur*c[(x>>i)&1][(y>>i&1)];
            }
            cout<<ans+1<<endl;
        } else {
            i64 ans;cin>>ans;
            ans--;
            int x=0,y=0; 
            for(int i=0;i<n;i++){
                i64 cur=(1ll<<2*i);
                if(ans%(4*cur)==cur){//1是
                    x+=(1ll<<i);
                    y+=(1ll<<i);
                }else if(ans%(4*cur)==2*cur){//2是左下角
                    x+=(1ll<<i);
                }else if(ans%(4*cur)==3*cur){
                    y+=(1ll<<i);
                }
                ans-=ans%(4*cur);
            }
            cout<<x+1<<" "<<y+1<<endl;
            // cout<<"Unknown"<<endl;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        Automatic_AC_machine();
    }
    return 0;
}