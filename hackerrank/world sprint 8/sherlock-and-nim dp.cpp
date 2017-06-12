#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, ll>
#define ppp pair<pp, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 30
#define base 311097
#define maxN 100011
typedef long long ll;
typedef long double ld;
using namespace std;
int nt, n;
int a[N];
int L[maxN][N];
int R[maxN][N];
bool dp[maxN];

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);

    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        int minVal = a[1];
        for (int i = 2; i <= n; i++)
            minVal = min(minVal, a[i]);

        if (n == 1) {
            cout << "Sherlock\n";
            continue;
        }

        for (int h = 1; h <= minVal; h++) {
            L[h][0] = 0;
            for (int i = 1; i <= n; i++)
                L[h][i] = L[h][i - 1] ^ (a[i] - minVal + h);
            R[h][n + 1] = 0;
            for (int i = n; i >= 1; i--)
                R[h][i] = R[h][i + 1] ^ (a[i] - minVal + h);
        }

        dp[0] = 0;
        int rr = 0;
        for (int i = 1; i <= n; i++)
            rr = rr ^ (a[i] - minVal);
        dp[0] = (rr > 0);

        bool tmp = dp[0];

        for (int h = 1; h <= minVal; h++) {
            dp[h] = false;
            for (int i = 1; i <= n; i++) {
                if (n > 2 && L[h][i - 1] ^ R[h][i + 1] == 0)
                    dp[h] = true;
            }
            if (!tmp) dp[h] = true;
            tmp &= dp[h];
        }
        if (dp[minVal])
            cout << "Sherlock\n";
        else
            cout << "Watson\n";
    }

    /**/ return 0;
}
