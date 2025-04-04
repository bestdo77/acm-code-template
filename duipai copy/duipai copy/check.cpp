#include<bits/stdc++.h>
using namespace std;
int main()
{
    while (1) //一直循环，直到找到不一样的数据
    {
    	cout <<1<<endl;
        system("data.exe");
        system("ansssw.exe");
        system("my.exe");
        int tem;
        if (system("fc my.txt ansssw.txt")) //当 fc 返回 1 时，说明这时数据不一样
            cin >>tem;                          //不一样就跳出循环
    }
    return 0;
}