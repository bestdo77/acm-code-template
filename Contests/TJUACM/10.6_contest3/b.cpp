#include <bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
const int maxn = 1e4 +10;
struct node{
    int x;
    int y;
}p[maxn];
double k(node a,node b){
    if(a.x == b.x){
        return 1e20;
    }
    else return 1.0*(a.y - b.y) / (a.x - b.x);
}
bool fabsg(node a,node b,node c){
    if(a.x == b.x && c.x!=a.x) return false;
    else if(a.x == c.x && b.x!=a.x) return false;
    else if(a.x == b.x && c.x != a.x) return false;
    else if(a.x == b.x && b.x == c.x) return true;
    else {
        return (a.y - b.y) * (a.x - c.x) == (a.y - c.y) * (a.x - b.x);
    }
}
signed main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>p[i].x>>p[i].y;
    }
    int flag = 0;
    int sum = 1;
    if(n<=6){
        cout<<"possible";
        return 0 ;
    }
    for(int i = 2;!flag && i<=n;i++){
        //meijv diyitiao
        sum = 1;
        double one = k(p[1],p[i]);
        vector <int> noline;
        for(int j = 2;j<=n;j++){
            if(j == i) continue;
            if(fabsg(p[1],p[j],p[i])) sum ++;
            else{
                if(noline.size()<2) noline.push_back(j);
                else if(noline.size()==2){
                    if(!fabsg(p[j],p[noline[0]],p[noline[1]])) noline.push_back(j);
                }
            }
        }
            if(noline.size()<3||sum+3>=n) {
                flag = 1;
                break;
            }
            else{
                int ff = 0;
                //1
                int san = 0;
                double two = k(p[noline[0]],p[noline[1]]);
                int j;
                for(j = 2;j<=n;j++){
                    if(j==i||j==noline[0]||j==noline[1]||j==noline[2]) continue;
                    if(fabsg(p[1],p[j],p[i])) continue;
                    else if(fabsg(p[noline[1]],p[j],p[noline[0]])) continue;
                    else {
                        if(san == 0){
                            san = j;
                        }
                        else {
                            if(fabsg(p[noline[2]],p[j],p[san])) continue;
                            else {
                                break;
                            }
                        }
                    }
                    
                }
                if(j == n + 1){
                        flag = 1;
                    }
                //2
                two = k(p[noline[0]],p[noline[2]]);
                san = 1e-21;
                for(j = 2;!flag && j<=n;j++){
                    if(j==i||j==noline[0]||j==noline[1]||j==noline[2]) continue;
                    if(fabsg(p[1],p[j],p[i])) continue;
                    else if(fabsg(p[noline[2]],p[j],p[noline[0]])) continue;
                    else {
                        if(san == 0){
                            san = j;
                        }
                        else {
                            if(fabsg(p[noline[1]],p[j],p[san])) continue;
                            else {
                                break;
                            }
                        }
                    }
                    if(j == n){
                        flag = 1;
                    }
                }
                if(j == n + 1){
                        flag = 1;
                    }
                //3
                two = k(p[noline[2]],p[noline[1]]);
                san = 0;
                for(j = 2;!flag && j<=n;j++){
                    if(j==i||j==noline[0]||j==noline[1]||j==noline[2]) continue;
                    if(fabsg(p[1],p[j],p[i])) continue;
                    else if(fabsg(p[noline[2]],p[j],p[noline[1]])) continue;
                    else {
                        if(san == 0){
                            san = j;
                        }
                        else {
                            if(fabsg(p[noline[0]],p[j],p[san])) continue;
                            else {
                                break;
                            }
                        }
                    }
                }
                if(j == n + 1){
                        flag = 1;
                    }
            }
        
    }
    
    if(flag) cout<<"possible";
    else cout<<"impossible";
}