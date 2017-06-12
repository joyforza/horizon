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
int nt;
string s;
int k, n;
int dp[2222222];
int qu[2222222];
bool f[2222222];

int getStt(int val, int l, int r) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int bit = (val >> i) & 1;
        if (i >= l && i <= r) bit = 1 - bit;
        if (bit) ret = ret | (1 << i);
    }
   // cout << val << " --> " << ret << "\n";
    return ret;
}

void split(int x) {
    for (int i = 0; i < n; i++)
        if ((x >> i) & 1)
            cout << "+";
    else
        cout << "-";
    cout << "\n";
}

int main() {
    //freopen("A.in", "r", stdin);
    freopen("A_2.ou", "w", stdout);
    ios::sync_with_stdio(false);

       cin >> n >> k;
       // cin >> s >> k;
       // n = s.size();

        int stt = 0;

        for (int i = 0; i < n; i++)
            if (s[i] == '+')
                stt |= (1 << i);

        int beginStt = (1 << n) - 1;
        for (int i = 0; i < (1 << n); i++) dp[i] = inf;
        dp[beginStt] = 0;

        memset(f, false, sizeof(f));
        int l = 1;
        int r = 1;
        qu[1] = beginStt;
        f[beginStt] = true;

        while (l <= r) {
            int node = qu[l]; l++;
            for (int i = 0; i < n - k + 1; i++) {
                int newNode = getStt(node, i, i + k - 1);
                if (f[newNode] == false) {
                    dp[newNode] = dp[node] + 1;
                    r++;
                    qu[r] = newNode;
                    f[newNode] = true;
                }
            }
        }

        for (int i = 0; i < (1 << n); i++)
            if (dp[i] != inf) {
                split(i);
                cout << "need = " << dp[i] << "\n";
            }

       /* cout << "Case #" << kk << ": ";
        if (dp[stt] == inf) cout << "IMPOSSIBLE\n";
        else
            cout << dp[stt] << "\n"; */

    /**/ return 0;
}
