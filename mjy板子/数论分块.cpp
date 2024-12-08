#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int ans=0;
    for(int i = 1,j;i <=n;i = j + 1){
        j = n / (n / i);
        ans += (sum_f[j] - sum_f[i-1]) * g[n / i];
    }
}