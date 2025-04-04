#include <iostream>
#define db(x) std::cout << (x) << " "
#define cendl std::cout << std::endl

void pa(auto M, auto n, auto m) {
    for (int i = 1; i <=n; i++) {
        for (int j = 1; j <=m; j++) {
            db(M[i * m + j]);
        }
        cendl;
    }
}

int main() {
    int n = 3; // 假设 n = 3
    int a[n][n] = {

        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    pa(&a[0][0], n-1, n-1); // 调用函数
    return 0;
}