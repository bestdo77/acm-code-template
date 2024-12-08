#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll a[N];
struct str{
    ll sum;
    ll num;
};

void Atomatic_AC_machine(){
    ll n;
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i];
    }
    stack <str> st;
    for(ll i=n;i>=1;i--){
        if(st.empty()){
            st.push({a[i],1});
            continue;
        }
        ll sum=a[i];
        ll num=1;
        while(!st.empty()&&sum/num>=st.top().sum/st.top().num){
            sum+=st.top().sum;
            num+=st.top().num;
            st.pop();
        }
        st.push({sum,num});
    }
    ll ans=1;
    ll mx=0,mn=1e14;
    while(!st.empty()){
        ll sum=st.top().sum;
        ll num=st.top().num;
        if(sum%num==0) mx=max(mx,sum/num),mn=min(mn,sum/num);
        else mx=max(mx,sum/num+1),mn=min(mn,sum/num);
        st.pop();
    }
    cout<<mx-mn<<endl;
}


signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}