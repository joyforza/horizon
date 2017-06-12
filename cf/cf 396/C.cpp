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
const long long oo = (ll)1e18;
using namespace std;

int dp[1010];
int n;
int a[30];
string s;

int cnt[1010][30];
int need[1010];

bool check(int l, int r) {
    int len = r - l + 1;

    for (int i = 0; i < 26; i++) {
        int num = cnt[r][i] - cnt[l - 1][i];
        if (num == 0) continue;
        if (len > a[i]) return false;
    }
    return true;
}

int main() {
  //  freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;

    for (int i = 0; i < 26; i++) cin >> a[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 26; j++)
            cnt[i][j] = cnt[i - 1][j] + (s[i - 1] - 'a' == j);

    dp[0] = 1;
    need[0] = 0;

    for (int i = 1; i <= n; i++)
        need[i] = inf;

    int maxLen = -inf;

    for (int i = 1; i <= n; i++)
        for (int j = i - 1; j >= 0; j--)
            if (check(j + 1, i)) {
                dp[i] = (dp[i] + dp[j]) % mod;
                maxLen = max(maxLen, i - j);
                need[i] = min(need[j] + 1, need[i]);
            }
        else
            break;

    cout << dp[n] << "\n";
    cout << maxLen << "\n";
    cout << need[n];
    /**/ return 0;
}
