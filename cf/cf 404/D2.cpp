#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 200200
#define maxK 64
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
string s;
int dp[N];
int n;
int M[N];
int D[N];

int f[N];
int inv[N];

int pw(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1) {
            ret = (ll)ret * a % mod;
            b--;
        }
        else {
            a = (ll)a * a % mod;
            b /= 2;
        }
    }
    return ret;
}

int tohop(int n, int k) {
    return (ll)f[n] * inv[n - k] % mod * inv[k] % mod;
}



int main() {
   // freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    f[0] = 1;
    for (int i = 1; i < N; i++)
        f[i] = (ll)f[i - 1] * i % mod;

    for (int i = 0; i < N; i++)
        inv[i] = pw(f[i], mod - 2);

    cin >> s;
    n = s.size();
    for (int i = 1; i <= n; i++)
        M[i] = M[i - 1] + (s[i - 1] == '(');
    for (int i = n; i >= 1; i--)
        D[i] = D[i + 1] + (s[i - 1] == ')');

    int ret = 0;
    for (int i = 1; i < n; i++) {
        int mo = M[i];
        int dong = D[i + 1];
        int can = min(mo, dong);
        for (int j = 1; j <= can; j++)
            ret = (ret + (ll)tohop(mo, j) * tohop(dong, j) % mod) % mod;
    }

    cout << ret;
    /**/ return 0;
}
