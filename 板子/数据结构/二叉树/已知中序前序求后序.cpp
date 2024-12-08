#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
void binary_tree(string mid,string pre){
    if(mid.size() > 0){
        char ch = pre[0];
        int cur = mid.find(ch);
        binary_tree(mid.substr(0,cur),pre.substr(1,cur));
        binary_tree(mid.substr(cur+1),pre.substr(cur+1));
    	cout << ch;//前序遍历第一个就是树根
	 }
}
int main(){
    string a,b;
    cin >> a >> b;
    binary_tree(a,b);
    return 0;
}