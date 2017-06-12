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
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL doubl e
#define EPS 1e-9
#define ll long long
using namespace std;
int n, m;
string s;
int dp[55][3];

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++)
            dp[i][j] = inf;

    for (int i = 0; i < n; i++) {
            cin >> s;

            for (int j = 0; j < s.size(); j++) {
            int val = min(j, m - j);

            if (s[j] >= 'a' && s[j] <= 'z') {
                dp[i][0] = min(dp[i][0], val);
            }
            else
            if (s[j] >= '0' && s[j] <= '9') {
                dp[i][1] = min(dp[i][1], val);
            }
            else {
                dp[i][2] = min(dp[i][2], val);
            }
            }
    }

    int ret = inf;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
            if (i != j && j != k && i != k)
                ret = min((ll)ret, (ll)dp[i][0] + dp[j][1] + dp[k][2]);
    cout << ret;

    /**/ return 0;
}
