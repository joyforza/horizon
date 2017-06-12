#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;

int n, a;
int x[N];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> a;
    for (int i = 1; i <= n; i++)
        cin >> x[i];
    sort(x + 1, x + n + 1);
    if (a <= x[1]) {
        if (n == 1)
            cout << 0;
        else
            cout << x[n - 1] - a;
    }
    else
    if (a >= x[n]) {
        if (n == 1)
            cout << 0;
        else
            cout << (a - x[2]);
    }
    else {

        /// cut first
        int ret = 1000000001;

        if (a <= x[2])
            ret = min(ret, x[n] - a);
        else
            ret = min(ret, min(a - x[2], x[n] - a) + x[n] - x[2]);

        /// cut last
        if (a >= x[n - 1])
            ret = min(ret, a - x[1]);
        else
            ret = min(ret, min(a - x[1], x[n - 1] - a) + x[n - 1] - x[1]);
        cout << ret;
    }
    /**/ return 0;
}
