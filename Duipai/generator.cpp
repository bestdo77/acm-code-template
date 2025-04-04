#include <iostream>
#include <random>
using namespace std;

int main() {
    // 设置随机数引擎
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 1000);

    // 生成两个随机整数作为测试数据
    int n = dis(gen);
    cout<<n<<endl;
    for(int i=1;i<=n;i++){
        cout<<dis(gen)<<" ";
    }
    cout<<endl;
    return 0;
}