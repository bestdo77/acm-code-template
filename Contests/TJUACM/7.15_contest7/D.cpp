#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f
struct node{
    int x,pos;
}a[3100000];
int ansl[3100000];
int ansr[3100000];
double ans1l[3100000];
double ans1r[3100000];
stack<node> stacks;
const int MAXN=1e3+10;
signed main(){
    //单调栈维护向左或向右的第一个比自己大/小的元素
    //如果维护第一个它大的数，那么单调栈应该是递减栈，如果维护比它小的，应该是递增。
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x;
        a[i].pos=i;
    }
    node tmp={inf,0};
    stacks.push(tmp);
    for(int i=1;i<=n;i++){
        while(a[i].x>=stacks.top().x){
            stacks.pop();
        }
        ansl[i]=stacks.top().pos;
        stacks.push(a[i]);
    }
    node tmp={inf,n+1};
    while(!stacks.empty()) stacks.pop();
    stacks.push(tmp);
    for(int i=n;i>=1;i--){
        while(a[i].x>=stacks.top().x){
            stacks.pop();
        }
        ansr[i]=stacks.top().pos;
        stacks.push(a[i]);
    }

    for(int i=1;i<=n;i++){
        if(ansl[i]==0) ans1l[i]=0;
        else{
            int p,q;
            p=ansl[i];
            q=i;
            int k=a[p].x-a[p+1].x;
            ans1l[i]=((a[q].x-a[p+1].x)+(q-p-1)*k)/k;
        }
    }

    for(int i=1;i<=n;i++){
        if(ansr[i]==n+1) ans1r[i]=0;
        else{
            int p,q;
            p=ansr[i];
            q=i;
            int k=a[p].x-a[p-1].x;
            ans1r[i]=((a[q].x-a[p-1].x)+(p-q-1)*k)/k;
        }
    }
    double maxx=0;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,max(ans1l[i],ans1r[i]));
    }
    int anss=0;
    for(int i=1;i<=n;i++){
        if(ans1l[i]==maxx||ans1r[i]==maxx) anss=i;
    }
    int t=0;
    if(ans1l[anss]>ans1r[anss]){
        t=1;
    }

    int N,D;
    int p,q;
    if(t==1){
        p=ansl[anss];
        q=anss;
        int k=a[p].x-a[p+1].x;
        N=(a[q].x-a[p+1].x)+(q-p-1)*k;
        D=k;
        if(__gcd(N,D)==k){
            cout<<N/k<<endl;
        }else{
            cout<<N/__gcd(N,D)<<"/"<<D/__gcd(N,D)<<endl;
        }
    }else{
        p=ansr[anss];
        q=anss;
        int k=a[p].x-a[p-1].x;
        N=(a[q].x-a[p-1].x)+(p-q-1)*k;
        D=k;
        if(__gcd(N,D)==k){
            cout<<N/k<<endl;
        }else{
            cout<<N/__gcd(N,D)<<"/"<<D/__gcd(N,D)<<endl;
        }
    }
   
    return 0;
}