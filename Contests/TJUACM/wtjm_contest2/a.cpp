#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
#define int long long
const int inf=0x3f3f3f3f;
const int infll=0x3f3f3f3f3f3f3f3f;
#define pii pair <int,int>
#define endl "\n"
const int N=200050;
struct node {
    int x,y,type;
}A[N];
int cmp(node x,node y){
    if (x.x!=y.x)return x.x<y.x;
    return x.y<y.y;
}
int cmp2(node x,node y){
    return x.y<y.y;
}

int abss(int x){
    if (x<0)return -x;
    return x;
}
node B[N];
double mindis;
double res;
void upd(node a, node b) {
   double dis=sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
   if (dis<res&&a.type!=b.type) res=dis;
   if (dis<mindis)mindis=dis;
}

void solve(int l, int r) {
    if (r-l<=3){
        for (int i=l;i<=r;i++){
            for (int j=i+1;j<=r;j++) upd(A[i],A[j]);
        }
        sort (A+l,A+r+1,cmp2);
        return ;
    }

    int mid=(l+r)/2;
    int midx=A[mid].x;
    solve(l,mid), solve(mid+1,r);
    inplace_merge(A+l,A+mid+1,A+r+1,cmp2);

    int siz=0;
    for (int i=l;i<=r;i++){
        if (abss(A[i].x-midx)<mindis){
            for (int j=siz;j>=1&&A[i].y-B[j].y<mindis;j--){
                upd(A[i],B[j]);
            }
            B[++siz]=A[i];
        }
    }
}
signed main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >>t;
    while (t--){
        int n;
        cin >>n;
        for (int i=1;i<=n;i++){
            cin >>A[i].x>>A[i].y;
            A[i].type=0;
        }
        for (int i=1;i<=n;i++){
            cin >>A[i+n].x>>A[i+n].y;
            A[i].type=1;
        }
        sort (A+1,A+1+n*2,cmp);
        mindis = infll;
        res=infll;
        solve(1,2*n);
        cout <<fixed<<setprecision(3)<<res<<endl;
    }
}
