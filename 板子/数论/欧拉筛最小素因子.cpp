#include <bits/stdc++.h>
using namespace std;
const int N = 1E7;
 
int sg[N + 1];
bool isprime[N+1];
vector<int> minp, primes;
 
void sieve(int n) {
    minp.assign(n + 1, 0);
    primes.clear();
    
    for (int i = 2; i <= n; i++) {
        if (minp[i] == 0) {
            minp[i] = i;
            primes.push_back(i);
            isprime[i]=1;
        }
        
        for (auto p : primes) {
            if (i * p > n) {
                break;
            }
            minp[i * p] = p;
            if (p == minp[i]) {
                break;
            }
        }
    }
}
int main(){
    int n;cin>>n;
    sieve(n);
    for(auto p: primes){
        cout<<p<<" ";
    }
    cout<<endl;
    for(int i=1;i<=n;i++){
        cout<<i<<": "<<minp[i]<<endl;
    }
    cout<<endl;
}