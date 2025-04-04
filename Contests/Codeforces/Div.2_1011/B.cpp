#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;

#define endl '\n'
#define all(x) x.begin(),x.end()

#ifndef __Local__
    int UUUU=0;
    #define db(x) UUUU++;
    #define cendl UUUU++;
    #define multicase UUUU++;
    void pa(auto a){}
    void pa(int *p,int n){}
    void pa(auto *M,auto n,auto m){}
#endif


const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;
int a[N];
void Atomatic_AC_machine(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(accumulate(a+1,a+1+n,0ll)==0){
        cout<<3<<endl;
        cout<<3<<" "<<n<<endl;
        cout<<1<<" "<<2<<endl;
        cout<<1<<" "<<2<<endl;
    }else{
        int p=0;
        int l=0,r=0;
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                p=i;
                break;
            }
        }
        for(int i=1;i<=p;i++){
            if(a[i]==0){
                l=1;
                break;
            }
        }
        for(int i=p+1;i<=n;i++){
            if(a[i]==0){
                r=1;
                break;
            }
        }

        // db(p<<" "<<l<<" "<<r)
        // cendl
        if(p==n){
            if(l){
                cout<<2<<endl;
                cout<<1<<" "<<n-1<<endl;
                cout<<1<<" "<<2<<endl;
            }else{
                cout<<1<<endl;
                cout<<1<<" "<<n<<endl;
            }
        }else if(p==1){
            if(r){
                cout<<2<<endl;
                cout<<2<<" "<<n<<endl;
                cout<<1<<" "<<2<<endl;
            }else{
                cout<<1<<endl;
                cout<<1<<" "<<n<<endl;
            }
        }else{
            if(r&&l){
                if(p==n-1){//说明最右边是0
                    cout<<3<<endl;
                    cout<<p<<" "<<p+1<<endl;
                    cout<<1<<" "<<p-1<<endl;
                    cout<<1<<" "<<2<<endl;
                }else if(p==2){//最左边是0
                    cout<<3<<endl;
                    cout<<1<<" "<<2<<endl;
                    cout<<2<<" "<<n-1<<endl;
                    cout<<1<<" "<<2<<endl;
                }else{
                    cout<<3<<endl;
                    cout<<p+1<<" "<<n<<endl;
                    cout<<1<<" "<<p-1<<endl;
                    cout<<1<<" "<<3<<endl;
                }
            }else if(r){
                cout<<2<<endl;
                cout<<p+1<<" "<<r<<endl;
                cout<<1<<" "<<p+1<<endl;
            }else if(l){
                cout<<2<<endl;
                cout<<1<<" "<<p<<endl;
                cout<<1<<" "<<(n-p+1)<<endl;
            }else{
                cout<<1<<endl;
                cout<<1<<" "<<n<<endl;
            }
        }
    }
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    cin>>t;
    while(t--){
        multicase
        Atomatic_AC_machine();
    }
    return 0;
}