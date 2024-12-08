#include <bits/stdc++.h>

#define MOD 998244353
#define MAX_N 100000
#define MAX_PRIME 100000

// Function to perform prime factorization
void prime_factors(int n, int* factors, int* count) {
    int d = 2;
    *count = 0;
    while (d * d <= n) {
        if (n % d == 0) {
            factors[*count] = d;
            (*count)++;
            while (n % d == 0) {
                n /= d;
            }
        }
        d++;
    }
    if (n > 1) {
        factors[*count] = n;
        (*count)++;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int attractiveness[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &attractiveness[i]);
    }

    // Initialize DP array
    int dp[n];
    dp[0] = 1;

    // Initialize prefix sums for each prime factor
    int prefix_sums[MAX_PRIME + 1] = {0};

    // Precompute prime factors for each city
    int factors[MAX_N][10];  // Assuming each number has at most 10 prime factors
    int factor_counts[MAX_N];

    for (int i = 0; i < n; i++) {
        prime_factors(attractiveness[i], factors[i], &factor_counts[i]);
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) {
            for (int j = 0; j < factor_counts[i]; j++) {
                dp[i] = (dp[i] + prefix_sums[factors[i][j]]) % MOD;
            }
        }

        // Update prefix sums
        for (int j = 0; j < factor_counts[i]; j++) {
            prefix_sums[factors[i][j]] = (prefix_sums[factors[i][j]] + dp[i]) % MOD;
        }
    }

    printf("%d\n", dp[n - 1]);

    return 0;
}