#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N],sum,n;
bool check(int x){
    if(x==1||x==2) return 1;
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 0;
    }
    return 1;
}
bool check2(int x){
    int sm=0;
    if(x==2){
        for(int i=1;i<=n;i++){
            if(a[i]%2) return 0;
            else sm+=2;
        }
        return sm<=sum;
    }
    for(int i=1;i<=n;i++){
        if(a[i]%2) sm+=x;
        else sm+=2*x;
    }
    return sm<=sum;
}
signed main(){
    vector<int> op;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    if(*max_element(a+1,a+1+n)==*min_element(a+1,a+1+n)&&*max_element(a+1,a+1+n)==2){
        cout<<"YES"<<endl;
        cout<<2<<endl;
        return 0;
    }
    for(int i=2;i*i<=sum;i++){
        if(sum%i==0){
            if(i*i==sum){
                if(check(i)) op.emplace_back(i);
            }else{
                if(check(i)) op.emplace_back(i);
                if(check(sum/i)) op.emplace_back(sum/i);
            }
        }
    }
    vector<int> ans;
    for(auto it:op){
        if(check2(it)){
            ans.push_back(it);
        }
    }
    if(ans.size()){
        cout<<"YES"<<endl;
        sort(ans.begin(),ans.end());
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}