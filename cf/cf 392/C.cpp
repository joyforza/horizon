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
#define N 123
#define base 311097
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
int n, m;
int x, y;
ll k;
ll dp[N];
int rr[N + N];


int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);


    cin >> n >> m >> k >> x >> y;

    for (int i = 1; i <= n; i++)
        rr[i] = i;
    for (int i = n + 1; i < 2 * n; i++)
        rr[i] = rr[i - 1] - 1;

    if (n == 1) {
        ll Max = (k / m) + (k % m != 0);
        ll Min = (k / m);
        cout << Max << " " << Min << " ";
        if (y <= k % m)
            cout << Max;
        else
            cout << Min;

        return 0;
    }

    ll need = (k / m);
    ll du = k % m;

    for (int i = 2; i < n; i++) {
        ll low = need - i + 1;
        dp[i] += 2 * (low / (2 * n - 2));

        ll rm = low % (2 * n - 2);

        if (rm >= 1) dp[i]++;
        if (rm >= 2 * (n - i) + 1) dp[i]++;
    }

    {
        ll low = need;
        dp[1] += (low / (2 * n - 2));
        ll rm = low % (2 * n - 2);
        if (rm >= 1) dp[1]++;
    }

    {
        ll low = need - n + 1;
        dp[n] += (low / (2 * n - 2));
        ll rm = low % (2 * n - 2);
        if (rm >= 1) dp[n]++;
    }

    if (du > 0) {

        int pos = (need + 1) % (2 * n - 2);
        if (pos == 0) pos = 2 * n - 2;

        pos = rr[pos];


      //  cout << "in pos = " << pos << "\n";

        dp[pos]++;
        ll Min = dp[1];
        ll Max = dp[1];
        for (int i =  2; i <= n; i++) {
            Min = min(Min, dp[i]);
            Max = max(Max, dp[i]);
        }

        cout << Max << " " << Min << " ";
        if (pos == x) {
            if (y <= du)
                cout << dp[pos];
            else
                cout << dp[pos] - 1;
        }
        else
            cout << dp[x];
    }
    else {
        ll Min = dp[1];
        ll Max = dp[1];
        for (int i = 2; i <= n; i++) {
            Min = min(Min, dp[i]);
            Max = max(Max, dp[i]);
        }
        cout << Max << " " << Min << " " << dp[x];
    }
    /**/ return 0;
}
