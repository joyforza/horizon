#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 1010
#define inf 1000000001
#define mod 1000000007
typedef long long ll;
using namespace std;
map<pp, int> M;
int q, n, k;
int f[N];

int com(int n, int k) {
    cout << n << " "<< k << "\n";

    if (k == 0) return f[n];
    if (k >= n) return 0;

    if (M.count(mp(n, k))) return M[mp(n, k)];
    int ret = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++)
            ret = (ret + (ll)com(j, i) * com(n - j - 1, k - i - 1) % mod) % mod;
    }
    M[mp(n, k)] = ret;
    return ret;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    f[0] = 1;
    for (int i = 1; i < N; i++) f[i] = (ll)f[i - 1] * i % mod;
    cin >> q;
    while (q--) {
        cin >> n >> k;
        cout << com(n, k) << "\n";
    }
    /**/return 0;
}
