#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
#define pii pair<int, int>
#define endl '\n'
const int N=1e3+10;
const int N1=1e3+10;
const int mod=1e9+7;
#define db long double
struct Point {
    db x, y,id;
    Point(db id = 0,db x = 0, db y = 0) : id(id), x(x), y(y) {}  // 构造函数, 初始值为 0
}p[N];
int pos;  //基准点
int cross(Point p0, Point p1, Point p2) {
	return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
int dis(Point p1, Point p2) {
	return (p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y);
}
bool cmp(Point p1, Point p2) {
	int tmp = cross(p[pos], p1, p2);
	if (tmp > 0) return true;
	else if (tmp == 0 && dis(p[pos], p1) < dis(p[pos], p2)) return true;
	else return false;
}
void Atomatic_AC_machine(){
    int n;cin>>n;
    vector<int> ans;
    for(int i=1;i<=n;i++){
        int id,x,y;
        cin>>id>>x>>y;
        p[i]=Point(id,x,y);
        if(p[i].y<p[1].y) swap(p[i],p[1]);
    }
    ans.push_back(p[1].id);
    cout<<n<<" ";
    pos=1;
    for(int i=2;i<=n;i++){
        sort(p+i,p+1+n,cmp);
        ans.push_back(p[i].id);
        pos=i;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        Atomatic_AC_machine();
    }
    return 0;
}