#include <bits/stdc++.h>
using namespace std;
#define ls k<<1
#define rs k<<1|1

const int maxn = 1e5+10;

int a[maxn];
struct node{
    int sum;
}tre[maxn<<2];
void modify(int k,int l,int r,int pos,int val){
    if(l == r){tre[k].sum = max(tre[k].sum,val);return;}
    int mid = l+r>>1;
    if(pos<=mid) modify(ls,l,mid,pos,val);
    else modify(rs,mid+1,r,pos,val);
    return;
}
int unq[maxn];
int main(){
    int n,k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
        unq[i] = a[i];
    }
    sort(a+1,a+1+n);
    int ans = 1;
    int x = a[1];
    for(int i = 2;i<=n;i++){
        if(a[i] - x >= k) ans++,x = a [i];
    }
    cout<<ans<<endl;
}