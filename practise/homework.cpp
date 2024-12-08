#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    int p = 1,q = 1;
    for(int i = 0;i<5;i++){
        p*=(95-i);
        q*=(100-i);
    }
    cout<<p<<" "<<q<<endl;
    int gcdd = __gcd(p,q);
    p/=gcdd;
    q/=gcdd;
    cout<<p<<'/'<<q<<endl;
    cout<<(long long)q-p<<'/'<<q;
}