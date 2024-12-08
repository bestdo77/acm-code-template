#include <bits/stdc++.h>
using namespace std;
map <string,int> mp;
int main (){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n;
    cin >>n;
    for (int i=1;i<=n;i++){
        string tem;
        cin >>tem;
        mp[tem]++;
        if (mp[tem]>=(n/2+1)){
            cout <<tem<<endl;
            return(0);
        }
    }
    cout <<"uh-oh"<<endl;
}