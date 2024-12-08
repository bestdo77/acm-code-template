#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        int p,q;
        cin>>p>>q;
        int gcdd = __gcd(p,q);
        p/=gcdd;
        q/=gcdd;
        int flag = 0;
        for(int i = 1;i<=sqrt(q)+2;i++){
            if(q%i == 0){
                int a = i;
                int b = q/i;
                if(a*a+b*b == p){
                    cout<<a<<" "<<b<<endl;
                    flag = 1;
                    break;
                } 
            }
        }
        if(flag){
            continue;
        }
        else{
            cout<<0<<" "<<0<<endl;
        }
    }
}