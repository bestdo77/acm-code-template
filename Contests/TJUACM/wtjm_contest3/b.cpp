#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
const int N1=210;
double d[N1][N1];
pair<double,double> p[N1];
double dis(int i,int j){
    return sqrt((p[i].first-p[j].first)*(p[i].first-p[j].first)+(p[i].second-p[j].second)*(p[i].second-p[j].second));
}
int main(){
    int n;
    int cnt=0;
    while(cin>>n&&n){
        for(int i=1;i<=n;i++){
            cin>>p[i].first>>p[i].second;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                d[i][j]=dis(i,j);
            }
        }
        for(int k=1;k<=n;k++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    d[i][j]=min(max(d[i][k],d[k][j]),d[i][j]);
                }
            }
        }
        cout<<"Scenario #"<<++cnt<<endl;
        cout<<fixed<<setprecision(4)<<"Frog Distance = "<<d[1][n]<<endl;

    }
}