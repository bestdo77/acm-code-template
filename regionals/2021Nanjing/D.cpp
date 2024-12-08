#include <bits/stdc++.h>
using namespace std;
int a[100];
int main (){
    freopen("data.in","r",stdin);
    freopen("D.out","w",stdout);
   int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]<a[j]){
                cnt++;
                swap(a[i],a[j]);
            }
        }
    }
    cout<<cnt<<endl; 
    // for(int i=1;i<=n;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
}