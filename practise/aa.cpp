#include <bits/stdc++.h>
using namespace std;
int check(int i){
    int res=0;
    while (i){
      //  cout <<i<<endl;
        res=max(res,i%10);
        i/=10;
    }
    return res;
}
int main(){
    int t;cin>>t;
    while(t--){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int l=l1+l2,r=r1+r2;
        int p=10;
        if(r-l>10) cout<<9<<endl;
        else {
             int res=0;
            for (int i=l;i<=r;i++){
                res=max(res,check(i));
               // cout <<res<<endl;
            }
            cout <<res<<endl;
        }
    }
}