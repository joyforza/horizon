#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
int  nt;
int n, q;
int a[100100];
ll s[100100];

int compute(int x) {
    int l = 1;
    int r = n;
    int m = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] <= x) {
            m = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    l = 1;
    r = m;
    int ret = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        ll need = (ll) x * (m - mid + 1) - (s[m] - s[mid - 1]);
        if (need <= mid - 1) {
            ret = m - mid + 1;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ret + (n - m);
}

int main() {
    //freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> nt;
    while(nt--) {
        cin >> n >> q;
        for (int i = 1; i <= n; i++) cin >> a[i];
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];

        while(q--) {
            int x;
            cin >> x;
            cout << compute(x) << "\n";
        }
    }
	return 0;
}
