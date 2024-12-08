#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
double a[100][100];
int n;
bool eq(double x,double y){
	return fabs(x-y)<1e-9;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n+1;j++) cin>>a[i][j];
	}
	int nwline=1;
	for(int k=1;k<=n;k++){
		int maxi=nwline;
		for(int i=nwline+1;i<=n;i++){
			if(fabs(a[i][k]>fabs(a[maxi][k]))) maxi=i;
		}
		if(eq(a[maxi][k],0)){
			continue;
		}
		swap(a[nwline],a[maxi]);
		
		for(int i=1;i<=n;i++){
			if(i==nwline) continue;
			if(!eq(a[nwline][k],0)){
    				double div=a[i][k]/a[nwline][k];	
    			for(int j=k;j<=n+1;j++){
    				a[i][j]-=a[nwline][j]*div;
    			}
			}
		}
		nwline++;
	}
	if(nwline<=n){
		while(nwline<=n){
			if(!eq(a[nwline][n+1],0)){
				cout<<-1;
				return 0;
			}
			nwline++;
			}
		cout<<0<<endl;	
	}else{
		for(int i=1;i<=n;i++)
         if(eq(a[i][n+1]/a[i][i],0)) cout<<"x"<<i<<"=0.00"<<endl;
			else printf("x%d=%.4lf\n", i, a[i][n+1]/a[i][i]);
	}
	return 0;
}