#include <iostream>
#include <vector>
#include <unordered_map>

long long solve(const std::vector<int>& A, int M) {
    // 前缀和初始化为0
    long long prefix_sum = 0;
    // 计数器用于记录模M后前缀和出现的次数
    std::unordered_map<long long, long long> count;
    // 总和初始化为0
    long long total = 0;

    // 初始情况下，前缀和为0的情况出现了一次
    count[0] = 1;

    for (int a : A) {
        // 更新前缀和
        prefix_sum += a;
        // 计算当前前缀和模M的值
        long long mod_sum = prefix_sum % M;
        if (mod_sum < 0) mod_sum += M; // 确保mod_sum是非负的
        // 使用哈希表中的信息更新总和
        total += count[mod_sum];
        // 更新哈希表中当前mod_sum的计数
        count[mod_sum]++;
    }

    return total;
}

int main() {
    std::vector<int> A = {1, 2, 3};
    int n,M = 3;
    std::cin>>n>>M;
    A.clear();
    for(int i=1;i<=n;i++){
        int x;std::cin>>x;
        A.push_back(x);
    }
    std::cout << solve(A, M) << std::endl; // 输出应该是 4
    return 0;
}