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
#define N 100010
#define base 311097
#define MAXN 505
#define MAXE 1000001
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
ll sum[N];
int n;
ll dp[N];

int getpos(int x, int i) {
    int l = 0;
    int r = i - 1;
    int ret = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (sum[i] - sum[mid] <= x) {
            ret = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ret;
}

int main() {
    //freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1] + 20;

        int p1 = getpos(90, i);
        int p2 = getpos(1440, i);
        if (p1 != -1)
            dp[i] = min(dp[i], dp[p1] + 50);
        if (p2 != -1)
            dp[i] = min(dp[i], dp[p2] + 120);
    }

    for (int i = 1;  i <= n; i++)
        cout << dp[i] - dp[i - 1] << "\n";
    /**/ return 0;
}
