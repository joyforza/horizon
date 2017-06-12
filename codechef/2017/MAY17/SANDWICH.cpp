#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 200010
#define mod 1000000007
typedef long long ll;
using namespace std;
int nt;
int n, k, m;
int dp[1111][111];


int main() {
	freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n >> k >> m;
        int p = n / k + (n % k != 0); /// divide to p part

        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= k; i++) dp[i][1] = 1;

        for (int j = 2; j <= p; j++)
            for (int i = j; i <= n; i++)
                for (int h = 1; h <= k; h++)
                if (i - h >= j - 1)
                    dp[i][j] = (dp[i][j] + dp[i - h][j - 1]) % m;

        cout << p << " " << dp[n][p] << "\n";
    }
    return 0;
}
