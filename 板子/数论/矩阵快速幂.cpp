#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=110;
const int mod=1e9+7;
struct martix{
    int a[N][N],len;
    martix(){
       memset(a,0,sizeof(a)); 
    }
    martix operator*(const martix p)&{
        martix tmp;
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                for(int k=1;k<=len;k++){
                   tmp.a[i][j]+=a[i][k]*p.a[k][j];
                   tmp.a[i][j]%=mod;
                }
            }
        }    
        tmp.len=len;
        return tmp;
    }
    void print(){
        for(int i=1;i<=len;i++){
            for(int j=1;j<=len;j++){
                cout<<a[i][j]<<" ";
            }cout<<endl;
        }
    }
};
martix quickpow(martix x,int y){
    martix re;
    for(int i=1;i<=x.len;i++){
        re.a[i][i]=1;
    }
    re.len=x.len;
	while(y){
		if(y&1) re=re*x;
		x=x*x,y=y/2;//2的y次方等于4的y/2次方.	
	}
    
	return re;
}
signed main(){
    int n,m;cin>>n>>m;
    martix ma;
    ma.len=n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>ma.a[i][j];
        }
    }
    ma=quickpow(ma,m);
    ma.print();
    return 0;
}