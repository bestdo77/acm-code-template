#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using pii = pair<int,int>;
const i64 infll = 0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
#define endl '\n'
#define all(x) x.begin(),x.end()
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());




const int N=1e6+10;
const int N1=5e3+10;
const i64 mod=1e9+7;
struct Time{
    int year,month,day;
    vector<int> m;
    Time(int _year,int _month,int _day){
        m.assign(13,0);
        year=_year;
        month=_month;
        day=_day;
        m[1]=m[3]=m[5]=m[7]=m[8]=m[10]=m[12]=31;
        m[4]=m[6]=m[9]=m[11]=30;
        if((year%4==0&year%100!=0)||(year%400==0)){
            m[2]=29;
        }else{
            m[2]=28;
        }
    }
    void add(){
        day++;
        if(day>m[month]){
            month++;
            day=1;
        }
        if(month>12){
            year++;
            month=1;
            if((year%4==0&year%100!=0)||(year%400==0)){
                m[2]=29;
            }else{
                m[2]=28;
            }
        }
    }
};
int cnt[10]={13,1,2,3,5,4,4,2,2,2};
int cal(int x){
    int res=0;
    if(x<10){
        res=cnt[0]+cnt[x];
    }else{
        while(x){
            res+=cnt[x%10];
            x/=10;
        }
    }
    return res;
}
void Atomatic_AC_machine(){
    Time cur(2000,1,1);
    int cnt=0;
    while(!(cur.year==2024&&cur.month==4&&cur.day==14)){
        int hua=cal(cur.year)+cal(cur.month)+cal(cur.day);
        if(hua>50) cnt++;
        cur.add();
    }
    cout<<cnt<<endl;
}   
signed main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1,i=0;
    // cin>>t;
    while(t--){
        // multicase
        Atomatic_AC_machine();
    }
    return 0;
}