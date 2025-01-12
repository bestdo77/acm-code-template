#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int a[N];
int n;

void qsort(int l, int r) {
    if (l >= r) return;
    int p=l;
	swap(a[l],a[p]);

    int i = l + 1, j = r;
    while (i <= j) {
        while (i <= j && a[i] < a[l]) i++;
        while (i <= j && a[j] > a[l]) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    cout<<i<<" "<<j<<endl;
    swap(a[l], a[j]);
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    qsort(l, j);
    qsort(i, r);
}

int main() {
    ios::sync_with_stdio(false);
    srand(time(0));
	cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    qsort(1, n);

    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}