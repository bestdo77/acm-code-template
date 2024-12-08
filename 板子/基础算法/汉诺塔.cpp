#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
const int N=1e6+10;
const int mod=1e9+7;
int a[N];
void move(int x,char a,char b){
    printf("Move %d from %c to %c\n",x,a,b);
}
void hanoi(int n,char x, char y,char z){
    if(n==0) return;
    hanoi(n-1,x,z,y);
    move(n,x,z);
    hanoi(n-1,y,x,z);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    hanoi(n,'A','B','C');
    return 0;
}