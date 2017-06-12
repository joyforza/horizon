#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

int day3_bp(std::vector<int> weight, std::vector<int> value, int limit) {

    int n = weight.size();

    int dp[22][101];
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < n; i++)
        for (int j = 0; j <= limit; j++) {
            for (int k = 1; k <= (limit - j) / weight[i]; k++) {
                dp[i + 1][j + k * weight[i]] =
                    max(dp[i + 1][j + k * weight[i]], dp[i][j] + value[i] * k);
            }
        }

    int ret = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= limit; j++)
            ret = max(ret, dp[i][j]);
    return ret;
}



int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);

    /**/ return 0;
}
