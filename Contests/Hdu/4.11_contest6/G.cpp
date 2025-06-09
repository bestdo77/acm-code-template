#include<bits/stdc++.h>​
 using namespace std;​
 int main()
 {
     cin.tie(nullptr)->sync_with_stdio(false);
     
     int sum, n;
     cin >> sum >> n;
     
     int res = 0;
     vector<int> row(n + 1), col(n + 1);
 ​
     function<void(int)> dfs = [&](int pos) -> void
     {
         int x = (pos + n - 1) / n, y = (pos % n ? pos % n : n);
         if (pos == n * (n - 1) + 1)
         {
             res ++;
             return ;
         }
 ​
         for (int i = 0; i <= sum; i++)
         {
             row[x] += i;
             col[y] += i;
             if (row[x] <= sum && col[y] <= sum)
             {
                 if (x == n && col[y] != sum)
                 {
 ​
                 }
                 else if (y == n && row[x] != sum)
                 {
 ​
                 }
                 else    dfs(pos + 1);
             }
             row[x] -= i;
             col[y] -= i;
         }
     };
     
     dfs(1);
     
     cout << res; 
     return 0;
 } 