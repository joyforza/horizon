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
#define N 400010
#define base 311097
#define N3 9
#define N4 11
typedef long long ll;
typedef long double ld;
using namespace std;
bool s[55];
vector <int> nxt[10010];
vector <int> ds;
int pat[10010];
int dp[400];
int tmp[400];
int tot[400010];
int n;

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    n = 400000;
    tot[1] = 9;
    tot[2] = 90;
    tot[3] = 303;
    tot[4] = 280;

    memset(pat, -1, sizeof(pat));
    s[0] = true;
    s[1] = true;
    for (int i = 2; i <= 50; i++)
    if (s[i] == false) {
        for (int j = i + i; j <= 50; j += i)
            s[j] = true;
    }

    for (int i = 0; i <= 9; i++)
    for (int j = 0; j <= 9; j++)
    for (int u = 0; u <= 9; u++)
    for (int v = 0; v <= 9; v++)
    for (int d = 0; d <= 9; d++) {
        if (s[i + j + u]) continue;
        if (s[j + u + v]) continue;
        if (s[u + v + d]) continue;
        if (s[i + j + u + v]) continue;
        if (s[j + u + v + d]) continue;
        if (s[i + j + u + v + d]) continue;

        nxt[i * 1000 + j * 100 + u * 10 + v].pb(d);
        ds.pb(i * 1000 + j * 100 + u * 10 + v);
        pat[i * 1000 + j * 100 + u * 10 + v] = (int)ds.size() - 1;
    }

    for (int i = 1; i <= 9; i++)
    for (int j = 0; j <= 9; j++)
    for (int u = 0; u <= 9; u++)
    for (int v = 0; v <= 9; v++)
    for (int d = 0; d <= 9; d++) {
        if (s[i + j + u]) continue;
        if (s[j + u + v]) continue;
        if (s[u + v + d]) continue;
        if (s[i + j + u + v]) continue;
        if (s[j + u + v + d]) continue;
        if (s[i + j + u + v + d]) continue;

        int val = j * 1000 + u * 100 + v * 10 + d;

        if (pat[val] == -1) {
            tot[5]++;
        }
        else {
            dp[pat[val]]++;
            tot[5]++;
        }
    }


    for (int i = 5; i < n; i++) {
        memset(tmp, 0, sizeof(tmp));

        for (int j = 0; j < ds.size(); j++)
        if (dp[j] > 0) {
            int val = ds[j];
            for (int k = 0; k < nxt[val].size(); k++) {
                int digit = nxt[val][k];
                int newState = (val * 10 + digit) % 10000;
                if (pat[newState] == -1)
                    tot[i + 1] = (tot[i + 1] + dp[j]) % mod;
                else
                    tmp[pat[newState]] = (tmp[pat[newState]] + dp[j]) % mod;
            }
        }

        for (int j = 0; j < ds.size(); j++) {
            tot[i + 1] = (tot[i + 1] + tmp[j]) % mod;
            dp[j] = tmp[j];
        }
    }

    int q;
    scanf("%d", &q);
    while (q--) {
        int x;
        scanf("%d", &x);
        printf("%d\n", tot[x]);
    }
    /**/ return 0;
}
