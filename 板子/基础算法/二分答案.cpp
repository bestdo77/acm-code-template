#include <iostream>
#include <algorithm>
#define int long long 
#define maxn 0x3f3f3f3f
using namespace std;
int a[200000];
bool check(int x){
}
signed main(){
	//上界max,下界min写二分查
    int min,max,ans;
	int l=min-1,r=max+1;

	while(l+1<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid;
	}
	ans=r;
	//二分找最小，这种单调性的，看哪个边在逼近，check后面是谁，就是谁在逼近。
	int k;
	while(l+1<r){
            int mid=(l+r)>>1;
            int p=check(mid);
            if(p<=k){
                r=mid;
                if(p==k) ans=mid;   
            }
            else if(p>k) l=mid;
        }
		//这种是寻找特定区间的，首先两边向中间逼近，但是找到结果不停下，找左边界点就小于等于的时候r=mid，找右边界点就大于等于的时候r=mid，然后结束之后再停止。
	return 0;
}