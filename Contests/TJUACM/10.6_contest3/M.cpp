#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n ==1){
        cout<<7<<" "<<9<<" "<<12;
    }
    else if(n==8){
        cout<<9<<" "<<11<<" "<<15;
    }
    else if(n==9){
        cout<<10<<" "<<20<<" "<<30;
    }
    else if(n<=9){
        cout<<1<<" "<<10<<" "<<100; 
    }
    else cout<<1<<" "<<2<<" "<<3;
}