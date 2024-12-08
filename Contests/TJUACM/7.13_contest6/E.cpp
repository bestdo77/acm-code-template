#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
int mp[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for(int i=2;i<=n;i++){
        cout<<"XOR 1 "<<i<<endl;
        cin>>a[i];
        mp[a[i]]++;
    }
    int flag=1;
    int p=0;
    int cru1=0,cru2=0;
    int a_1=0;
    for(int i=1;i<=(1<<n);i++){
         if(mp[0]){
            flag=-1;
            break;
        }
        if(mp[i]==2){
            p=i;
            flag=0;
            break;
        }
    }
    if(flag==1){
        for(int i=2;i<=n;i++){
            if(a[i]==1) cru1=i;
            if(a[i]==n-2) cru2=i;
        }
        cout<<"AND 1 "<<cru1<<endl;
        cin>>cru1;
        cout<<"AND 1 "<<cru2<<endl;
        cin>>cru2;
        a_1=cru1|cru2;
    }else{
        if(flag==0){
            for(int i=2;i<=n;i++){
                if(a[i]==p&&!cru1) cru1=i;
                else if(a[i]==p) cru2=i;
            }
            cout<<"AND "<<cru1<<" "<<cru2<<endl;
           	cin>>cru1;
            a_1=cru1^a[cru2];
        }else{
            for(int i=2;i<=n;i++){
                if(a[i]==0) p=i;
            }
            cout<<"AND 1 "<<p<<endl;
            cin>>a_1;
        }
        
    }
    cout<<"! ";
    for(int i=1;i<=n;i++){
        cout<<(a[i]^a_1)<<" ";
    }
    cout<<endl;
    return 0;
}