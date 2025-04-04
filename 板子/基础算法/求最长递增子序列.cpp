#include <bits/stdc++.h>
using namespace std;
int a[N];
vector<int> lis;
void push(int x){
    int pos=lower_bound(lis.begin(),lis.end(),x)-lis.begin();
    if(pos==lis.size()){
        lis.emplace_back(x);
    }else{
        lis[pos]=min(lis[pos],x);   
    }
}
void Atomatic_AC_machine(){
    int n,q;cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        push(a[i]);
    }
}   