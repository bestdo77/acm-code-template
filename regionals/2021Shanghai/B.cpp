#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int main(){
    for(int i=1;i<=1000;i++){
        for(int j=1;j<=1000;j++){
            int gcd=__gcd(i*i+j*j,i+j);
            cout<<(i*i+j*j)<<" "<<(i+j)<<" "<<(i*i+j*j)/gcd<<"/"<<(i+j)/gcd<<" "<<(i*i+j*j)*1.0/(i+j)<<endl;
        }
    }
}