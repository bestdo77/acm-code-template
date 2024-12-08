#include <bits/stdc++.h>

using namespace std;

template<class T> void fr(T &a, bool f = 0, char ch = getchar()) {
    for (a = 0; ch < '0' || ch > '9'; ch = getchar()) ch == '-' ? f = 1 : 0;
    for (; ch >= '0' && ch <= '9'; ch = getchar()) a = a * 10 + ch - '0';
    a = f ? -a : a;
}
int fr() {
    int a;
    return fr(a), a;
}

const int N = 1e3;
const int nx[] = {-1, 1, 0, 0};
const int ny[] = {0, 0, -1, 1};

/*
'/'  : t ^= 2
'\\' : t ^= 3
*/

int n, m, top, ans[N + 10][N + 10][6];
char mp[N + 10][N + 10], str[100];
bool vis[N + 10][N + 10];

struct Node {
    int x, y, t;
} stk[4 * N * N + 10];

int work(int X, int Y, int T) {
    int x = X, y = Y, t = T, res = 0;
    while (mp[x][y] != '#') {
        // printf("%d %d %d\n", x, y, t);
        bool flag = (vis[x][y] == 0);
        res += (vis[x][y] == 0), vis[x][y] = 1, stk[++top] = (Node){x, y, t};
        if (mp[x][y] == '/') t ^= 3;
        else if (mp[x][y] == '\\') t ^= 2;
        else if (mp[x][y] == '|') {
            if (t >= 2) t ^= 1;
            else if (flag) vis[x][y] = 0, res--;
        } else if (mp[x][y] == '-') {
            if (t <= 1) t ^= 1;
            else if (flag) vis[x][y] = 0, res--;
        }
        x += nx[t], y += ny[t];
        if (x == X && y == Y && t == T) return res;
    }
    return -res;
}

int main() {
    fr(n), fr(m);
    for (int i = 1; i <= n; i++) scanf("%s", mp[i] + 1);
    for (int i = 0; i <= m + 1; i++) mp[0][i] = mp[n + 1][i] = '#';
    for (int i = 0; i <= n + 1; i++) mp[i][0] = mp[i][m + 1] = '#';
    for (int _ = fr(), x, y, k; _--;) {
        fr(x), fr(y);
        scanf("%s", str + 1);
        if (str[1] == 'a') k = 0;
        else if (str[1] == 'b') k = 1;
        else if (str[1] == 'l') k = 2;
        else if (str[1] == 'r') k = 3;
        // else printf("%d %d\n", x, y);
        x += nx[k], y += ny[k];
        if (ans[x][y][k]) {
            printf("%d\n", ans[x][y][k]);
            continue;
        }
        int res = work(x, y, k);
        if (res < 0) {
            int up = top, uup = up, f = 0;
            // work(x, y, k ^ 1);
            while (uup) {
                Node tmp = stk[uup--];
                vis[tmp.x][tmp.y] = 0;
                // printf("(%d,%d, %d) : (%d,%d,%d,%c,%d)\n", x, y, k, tmp.x, tmp.y, tmp.t, mp[tmp.x][tmp.y], int(vis[tmp.x][tmp.y]));
                // f += vis[tmp.x][tmp.y], vis[tmp.x][tmp.y] = 0, ans[tmp.x][tmp.y][tmp.t] = f;
            }
            // up++;
            // while (up <= top) {
            //     Node tmp = stk[up++];
            //     printf("(%d,%d, %d) : (%d,%d,%d,%c,%d)\n", x, y, k, tmp.x, tmp.y, tmp.t, mp[tmp.x][tmp.y], int(vis[tmp.x][tmp.y]));
            //     f += vis[tmp.x][tmp.y], vis[tmp.x][tmp.y] = 0, ans[tmp.x][tmp.y][tmp.t ^ 1] = f;
            // }
            top = 0;
            ans[x][y][k] = -res;
        } else {
            while (top) {
                Node tmp = stk[top--];
                vis[tmp.x][tmp.y] = 0, ans[tmp.x][tmp.y][tmp.t] = res;
            }
        }
        // printf("%d\n", ans[x][y][k]);
        printf("%d\n", ans[x][y][k]);
    }
    return 0;
}
/*
4 4
---\
--||
--\/
----
2
1 1 right
2 4 above
*/