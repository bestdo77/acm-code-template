#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

const int N=1e6+10;
const int N1=5e3+10;
const int mod=1e9+7;

#define db(x) cerr<<x<<" ";
#define cendl cerr<<endl;
void print(vector<int> a){for(auto it:a) db(it);cendl}
int a[N];
int cnt[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(cnt[i]==0){
            if(i==n) cout<<"? "<<i<<" "<<i-1<<endl;
            else cout<<"? "<<i<<" "<<n<<endl;
            int d;cin>>d;   
            if(d==0){
                cout<<"! A"<<endl;
            }else{
                cout<<"! B"<<endl;
            }
            return;
        }
    }
    int pos1=0,posn=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1) pos1=i;
        if(a[i]==n) posn=i;
    }
    cout<<"? "<<pos1<<" "<<posn<<endl;
    int d;cin>>d;
    cout<<"? "<<posn<<" "<<pos1<<endl;
    int d1;cin>>d1;
    if(d1!=d||d1<n-1){
        cout<<"! A"<<endl;
    }else{
        cout<<"! B"<<endl;
    }
}   
signed main(){
    int t=1,i=0;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}