#include <bits/stdc++.h>
typedef long long ll;
const int maxx = 100010;
const int inf = 0x3f3f3f3f;
using namespace std;
struct node
{
    double a, b;
} edge[maxx];            //数组edge用来记录所有的点
node res[maxx];          //数组res用来记录凸包的点
bool cmp(node x, node y) //当x坐标值不同的时候，将x坐标值从小到大排序
{                        //当x坐标值相同的时候，以y值小的在前面
    if (x.a != y.a)
        return x.a < y.a;
    return x.b < y.b;
}
double cj(node i, node j, node c) //计算叉积
{
    return (i.a - c.a) * (j.b - c.b) - (i.b - c.b) * (j.a - c.a);
}
double dis(node x, node y) //计算两点之间的距离
{
    return sqrt((x.a - y.a) * (x.a - y.a) + (x.b - y.b) * (x.b - y.b));
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n, n)
    {
        for (int i = 0; i < n; i++)
            cin >> edge[i].a >> edge[i].b;
 
        if (n == 1)
        {
            cout << 0.00 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << fixed << setprecision(2) << dis(edge[0], edge[1]) << endl;
            continue;
        }
        sort(edge, edge + n, cmp);
        res[0] = edge[0];
        res[1] = edge[1];
        int tot = 2;
        for (int i = 2; i < n; i++) //下凸包
        {
            while (tot >= 2 && cj(edge[i], res[tot - 1], res[tot - 2]) > 0)
                tot--;
            res[tot] = edge[i];
            tot++;
        }
        int pop = tot;
        for (int i = n - 2; i >= 0; i--) //上凸包
        {
            while (tot >= pop && cj(res[tot - 1], edge[i], res[tot - 2]) < 0)
                tot--;
            res[tot] = edge[i];
            tot++;
        }
        double sum = 0;
        tot--;
        for (int i = 0; i < tot; i++)
            sum += dis(res[i], res[i + 1]);
        cout << fixed << setprecision(2) << sum << endl;
    }
    return 0;
}