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
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m;
int d[100100];
int a[100100];
bool f[100100];
int prv[100100];
int mask[100100];
ll sum;

bool check(int n) {
   // cout << "check = " << n << "\n";

    memset(f, false, sizeof(f));
    int cnt = 0;
    int pos = prv[n];

    //cout << pos << "\n";

    if (pos == 0) return false;
    if (m + sum > pos) return false;
    for (int i = pos; i >= 1; i--) {
        if (d[i] > 0 && f[d[i]] == false) {
            f[d[i]] = true;
            if (i - 1 < a[d[i]]) return false;
            cnt++;
        }
    }

   // cout << "cnt = " << cnt << endl;
    return (cnt == m);
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int i = 1; i <= m; i++) {
            cin >> a[i];
            sum += a[i];
    }

    for (int i = 1; i <= n; i++)
        if (d[i] > 0) prv[i] = i;
    else
        prv[i] = prv[i - 1];

    int l = 1, r = n;
    int ret = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ret = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    cout << ret;
    /**/ return 0;
}
