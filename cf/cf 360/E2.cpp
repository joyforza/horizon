#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 1000001
typedef long long ll;
typedef long double ld;
using namespace std;
int n, s;
bool f[555][555][555];
bool ret[555];
int c[555];

int main() {
  //  freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    sort(c + 1, c + n + 1);
    f[0][0][0] = true;
    for (int i = 1; i <= n; i++)
    for (int j = 500; j >= 0; j--)
    for (int k = 500; k >= 0; k--) {
        f[i][j][k] |= f[i - 1][j][k];
        if (j - c[i] >= 0)
            f[i][j][k] |= f[i - 1][j - c[i]][k];
        if (k - c[i] >= 0)
            f[i][j][k] |= f[i - 1][j][k - c[i]];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= s; j++)
    if (f[i][j][s - j]) {
        ret[j] = true;
        ret[s - j] = true;
    }

    int cnt = 1;
    for (int i = 1; i <= s; i++)
        if (ret[i]) cnt++;
    cout << cnt << "\n";
    cout << 0 << " ";
    for (int i = 1; i <= s; i++)
        if (ret[i])
            cout << i << " ";

    /**/ return 0;
}
