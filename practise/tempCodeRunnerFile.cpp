#include <iostream>
#include <algorithm>
using namespace std;
struct node{
    int x,y;
}a[6];
bool cmp(node a,node b){
    return a.x<b.x;
}
int main(){
    for(int i=1;i<=5;i++){
        a[i].x=(i+3)%5;
        a[i].y=0;
    }
    sort(a+1,a+1+5,cmp);
    for(int i=1;i<=5;i++){
        cout<<a[i].x<<" ";
    }cout<<endl;
    return 0;
}