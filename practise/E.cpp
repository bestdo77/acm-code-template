#include <bits/stdc++.h>
using namespace std;
int main (){
    int x,y,p,q;cin>>x>>y>>p>>q;
    int ly=0,ll=0,ry=x,rl=y;
    int cnt=0;//零从右到左
    while(ly!=x){
        if(cnt==2000){
            cout<<-1<<endl;
            return 0;
        }
        if(cnt%2==0){
            int tou=0;
            if(ry<=p){
                cnt++;
                break;
            }
            while(tou<p){
                if(rl>ry+q){
                    ll++;
                    rl--;
                    tou++;
                }else if(rl==ry+q){
                    if(p-tou>=2){
                        rl--,ll++;
                        ry--,ly++;
                        tou+=2;
                    }else{
                        rl--,ll++;
                        tou++;
                        break;
                    }
                }else{
                    ly++;
                    ry--;
                    tou++;
                }
            }
            if(rl>ry+q){
                cout<<"-1"<<endl;
                return 0;
            }
        }else{
            int tou=0;
            while(tou<p){
                if(ll>ly+q&&ly!=0){
                    ll--;
                    rl++;
                }
                tou++;
            }
            if(ll>ly+q&&ly!=0){
                cout<<"-1"<<endl;
                return 0;
            }
        }
        cnt++;
        cout<<ly<<" "<<ll<<" "<<ry<<" "<<rl<<endl;
    }
    cout<<cnt<<endl;
}