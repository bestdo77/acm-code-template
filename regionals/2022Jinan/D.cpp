#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
#define lmin 240
#define rmax 299
int n,m;//team,problem;
#define  teamij team[tt].problem[j+1]
struct Problem{
    char verdict;//+代表ac,?代表pending,-代表fail
    int presub,allsub,penalty;//封榜前提交次数,总提交次数,单题罚时
    int l,r;
};
struct Team{
    int AC,Penalty;//ac数,总罚时
    Problem problem[14];
}team[5000];
void contradict(int tt){//判断team_i是否矛盾
    int AC=team[tt].AC,Penalty=team[tt].Penalty;             
    for(int i=0;i<(1<<m);i++){//枚举每个题选或者不选,但是ac了一定要选,不ac一定不选,总选取等于AC
        int low=0,high=0;
        if(__builtin_popcount(i)!=AC) continue;
        bool flag=0;
        for(int j=0;j<m;j++){
            if(i&(1<<j)){
                if(teamij.verdict=='-'||teamij.verdict=='.'){flag=1;break;};
            }else{
                if(teamij.verdict=='+') {flag=1;break;};
            } 
        }
        if(flag) continue;
        // cout<<bitset<14>(i)<<endl;
        for(int j=0;j<m;j++){
            if(i&(1<<j)){
                if(teamij.verdict=='+'){
                    low+=teamij.penalty;
                    high+=teamij.penalty;
                }else{
                    teamij.l=teamij.penalty+240;
                    teamij.r=(teamij.allsub-1)*20+299;
                    low+=teamij.l;
                    high+=teamij.r;
                }
            }
        }
        if(low<=Penalty&&high>=Penalty){
            cout<<"Yes"<<endl;
            for(int k=1;k<=m;k++){
                int l=team[tt].problem[k].l,r=team[tt].problem[k].r;
                if(team[tt].problem[k].verdict=='+'){
                    cout<<"+ "<<team[tt].problem[k].allsub<<"/"<<team[tt].problem[k].penalty-20*(team[tt].problem[k].allsub-1)<<endl;
                }else if(team[tt].problem[k].verdict=='?'){
                    if(!(i&(1<<(k-1)))){
                        cout<<"- "<<team[tt].problem[k].allsub<<endl;
                        continue;
                    }
                    if(low+(r-l)<=Penalty){
                        cout<<"+ "<<team[tt].problem[k].allsub<<"/"<<299<<endl;
                        low+=(r-l);
                    }else{
                        int tim=Penalty-low; //当前差的时间,当前题的罚时去补
                        int nowsub=team[tt].problem[k].presub;
                        if(tim<=59){
                            cout<<"+ "<<team[tt].problem[k].presub+1<<"/"<<240+tim<<endl;
                            low=Penalty;
                            // cout<<"ssb"<<tim<<" "<<endl;
                            tim=0;
                        }else{
                            int cnt=(tim-59)/20+!!((tim-59)%20);
                            tim-=20*cnt;
                            cout<<"+ "<<team[tt].problem[k].presub+cnt+1<<"/"<<240+tim<<endl;
                            tim=0;
                            low=Penalty;
                        }
                    } 
                }else if(team[tt].problem[k].verdict=='-'){
                    cout<<"- "<<team[tt].problem[k].allsub<<endl;
                }else{
                    cout<<'.'<<endl;
                }
            }
            return;
        }
    }
    cout<<"No"<<endl;
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>team[i].AC>>team[i].Penalty;
        for(int j=1;j<=m;j++){
            cin>>team[i].problem[j].verdict;
            if(team[i].problem[j].verdict=='+'){
                int x=0,y=0;string s;bool flag=0;
                cin>>s;
                for(auto it:s){
                    if(it!='/'&&!flag) x*=10,x+=it-'0';
                    else if(it=='/') flag=1;
                    else y*=10,y+=it-'0'; 
                }
                team[i].problem[j].allsub=x;
                team[i].problem[j].penalty=20*(x-1)+y;
            }else if(team[i].problem[j].verdict=='?'){
                cin>>team[i].problem[j].presub>>team[i].problem[j].allsub;
                team[i].problem[j].presub=team[i].problem[j].allsub-team[i].problem[j].presub;
                if(team[i].problem[j].presub==team[i].problem[j].allsub)
                team[i].problem[j].verdict='-';
                team[i].problem[j].penalty=team[i].problem[j].presub*20;
            }else if(team[i].problem[j].verdict=='-'){
                cin>>team[i].problem[j].allsub;
            }
        }
    }
    for(int i=1;i<=n;i++){
        contradict(i);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    // cout<<(1000ll*(1<<13))<<endl;
    int t=1;
    while(t--){
        solve();
    }
    return 0;
}