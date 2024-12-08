#include <iostream>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;
#define pii pair<int,int>
struct node{
    int first,second;
    // bool operator< (node other){
    //     return first<other.first;
    // }
}a[6];
pii a[6];
map<string,int> mp;
// bool cmp(node a,node b){
//     if(a.first==b.first) return a.second<b.second;
//     else return a.first<b.first;
// }
int main(){
    mp["cde"]=1;
    mp["abc"]=1;
    mp["A"]=2;
    mp["B"]=2;
    mp["C"]=2;
    mp["D"]=3;
    for(auto it:mp){
        cout<<it.first<<" "<<it.second<<endl;
    }
    return 0;
}