#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int mod=1e9+7;
int n,len,a[N],b[N],addv[N];
vector<int> v[510];
void Sort(int x){//对块x进行排序
    v[x].clear();
    for(int i=(x-1)*len+1;i<=min(x*len,n);i++) v[x].push_back(a[i]);
    sort(v[x].begin(),v[x].end());
}
void modify(int l,int r,int c){
    for(int i=l;i<=min(b[l]*len,r);i++){//未成块元素直接修改
        a[i]+=c;
    }
    Sort(b[l]);
    if(b[l]!=b[r]){
        for(int i=(b[r]-1)*len+1;i<=r;i++){
            a[i]+=c;
        }//未成块元素修改
        Sort(b[r]);
    }
    for(int i=b[l]+1;i<b[r];i++){
        addv[i]+=c;
    }
}
int query(int l,int r,int c){
    int ret=0;
    for(int i=l;i<=min(b[l]*len,r);i++){
        if(a[i]+addv[b[l]]<c) ret++;
    }
    if(b[l]!=b[r]){
        for(int i=(b[r]-1)*len+1;i<=r;i++){
            if(a[i]+addv[b[r]]<c) ret++;
        }
    }
    for(int i=b[l]+1;i<b[r];i++){
        int tag=c-addv[i];
        ret+=lower_bound(v[i].begin(),v[i].end(),tag)-v[i].begin();
    }
    return ret;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    len=sqrt(n);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=(i-1)/len+1;//记录元素所属分块
        v[b[i]].push_back(a[i]);
    }
    for(int i=1;i<b[n];i++){
        sort(v[i].begin(),v[i].end());
    }
    int opt,l,r,c;
    for(int i=1;i<=n;i++){
        cin>>opt>>l>>r>>c;
        if(opt==0) modify(l,r,c);
        else cout<<query(l,r,c*c)<<endl;
    }
    return 0;
}