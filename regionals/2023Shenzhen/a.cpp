#include <bits/stdc++.h>
using namespace std;
const int N=200050;
#define pii pair <int,int>
int a[N];
struct node{
    int num,p;
}b[N];
int n;
vector <pii> ans;
int cmp(node x,node y){
    return x.num<y.num;
}
void opt1(int x){
    ans.push_back({1,x});
    for (int i=1;i<=n;i++){
        if (a[i]==x)a[i]++;
    }
}
void opt2(int x){
    ans.push_back({2,x});
    a[x]++;
}
void solvel(int l,int r);
void solver(int l,int r){
  //  cout <<"optr"<<" "<<l<<" "<<r<<endl;
    // for (int i=1;i<=n;i++)cout <<a[i]<<" ";
    // cout <<endl;
    // for (int i=1;i<=n;i++)cout <<b[i].num<<" "<<b[i].p<<" ";
    // cout <<endl;
    if (l>r)return ;
    else if (l==r)while (a[b[l].p]<b[l].num)opt2(b[l].p);
    else{
        int flag=1;
        for (int i=l;i<=r;i++){
            if (a[b[i].p]!=b[i].num){
                flag=0;
                break;
            }
        }
        if (flag) return ;
        for (int i=l;i<=r;i++){
            opt2(b[i].p);
        }
        while (a[b[l].p]<b[l].num)opt1(a[b[l].p]);
        int mid=(l+r)/2;
        while (b[mid+1].num==b[l].num&&mid<=r)mid++;
        solver(mid+1,r);
        solvel(l,mid);
    }
}
void solvel(int l,int r){
   // cout <<"optl"<<" "<<l<<" "<<r<<endl;
   // for (int i=1;i<=n;i++)cout <<a[i]<<" ";
    if (l>r)return ;
    else if (l==r)while (a[b[l].p]<b[l].num)opt2(b[l].p);
    else{
        int flag=1;
        for (int i=l;i<=r;i++){
            if (a[b[i].p]!=b[i].num){
                flag=0;
                break;
            }
        }
        if (flag) return ;
        int min=b[l].num;
        while (a[b[l].p]<min)opt1(a[b[l].p]);
        int mid=(l+r)/2;
        while (b[mid+1].num==min&&mid<=r)mid++;
        solver(mid+1,r);
        solvel(l,mid);
        
    }
}
int main (){
    cin >>n;
    for (int i=1;i<=n;i++){
        int tem;
        cin >>tem;
        b[i].num=tem;
        b[i].p=i;
    }
    sort (b+1,b+1+n,cmp);
    solvel(1,n);
    cout <<ans.size()<<endl;
    for (auto i:ans){
        cout <<i.first<<" "<<i.second<<endl;
    }
}
    