#include <iostream>
using namespace std;
void solve(){
    int l=0,r=1000;
    int x;
    // cout<<l<<" "<<r<<endl;
    while(l+1<r){
        int mid1=l+(r-l)/3;
        int mid2=l+2*(r-l)/3;
        cout<<"? "<<mid1<<" "<<mid2<<endl;
        cin>>x;
        if(x==(mid1+1)*(mid2+1)){
            r=mid1;
        }else if(x==mid1*mid2){
            l=mid2;
        }else{
            l=mid1,r=mid2;
        }
    }
    cout<<"!"<<" "<<l+1<<endl;
}   