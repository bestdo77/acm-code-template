#include <iostream>
#include <algorithm>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e6+10;
const int N1=1e3+10;
const int mod=1e9+7;
struct vec{
	int x,y,z;
	bool operator<(const vec &other)const{
		return z<other.z;
	}
}a[510000];
int ec=0;
int n,m;
int f[510000];
int find_f(int x){
	if(f[x]==x) return x;
	return f[x]=find_f(f[x]);
}
void join(int x,int y){
	int fx=find_f(x);
	int fy=find_f(y);
	if(fx!=fy){
		f[fx]=fy;
	}
}
int krusal(){//每次将权最小的边连入并查集，判断是否有环,同时如果连入边的个数小于n-1，说明不连通。
	int cnt=0,ans=0;
	sort(a+1,a+1+ec);
    for(int i=1;i<=n;i++){
        f[i]=i;
    }
	for(int i=1;i<=ec;i++){
		if(find_f(a[i].x)==find_f(a[i].y)) continue;
		else{
			cnt++,ans+=a[i].z;
			join(a[i].x,a[i].y);
		}
	}
	return ans;
}
signed main(){
    // ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    while(cin>>n&&n){
        ec=0;
        for(int i=1;i<=n;i++){
            int nw=-1,to=-1,w=0; 
            char x;cin>>x;
            int p;cin>>p;
            for(int j=1;j<=p;j++){
                char y;cin>>y;
                int w;cin>>w;
                a[++ec]={x-'A'+1,y-'A'+1,w};
            }
        }
        cout<<krusal()<<endl;
    }
    return 0;
}