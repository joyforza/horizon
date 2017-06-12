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
const long long oo = (ll)1e18;
using namespace std;
int nt;
double ret;
int Hp, n;

ll dp[55][1010];

double getSpell( string s) {
    int x = 0;
    int y = 0;
    int z = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'd') {
            for (int j = i + 1; j < s.size(); j++) {
                if (s[j] == '+' || s[j] == '-') {
                    for (int k = j + 1; k < s.size(); k++)
                        z = z * 10 + (s[k] - '0');
                    if (s[j] == '-') z = -z;
                    break;
                }
                y = y * 10 + (s[j] - '0');
            }
            break;
        }
        x = x * 10 + (s[i] - '0');
    }
    memset(dp, 0, sizeof(dp));

    int maxScore = y * x;
    dp[0][0] = 1;

    for (int i = 0; i < x; i++)
    for (int j = 0; j <= maxScore; j++)
    if (dp[i][j] > 0) {
        for (int p = 1; p <= y; p++)
            if (j + p <= maxScore)
                dp[i + 1][j + p] += dp[i][j];
    }

    ll omega = 1;
    for (int i = 1; i <= x; i++)
        omega *= y;

    ll tot = 0;
    for (int i = 0; i <= maxScore; i++)
        if (i + z >= Hp) {
            tot += dp[x][i];
        }
    return (1.0 * tot / omega);
}


string s;

int main() {
    freopen("45.in", "r", stdin);
    freopen("45.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        ret = 0;
        cin >> Hp >> n;
        for (int i = 1; i <= n; i++) {
            cin >> s;
            ret = max(ret, getSpell(s));
        }
        printf("Case #%d: %.6lf\n", kk, ret);
    }

    /**/ return 0;
}
