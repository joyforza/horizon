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
#define N 360010
#define base 311097
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
int nt;
int d[N], p[N];
int dp[N], a[N];
int n;
vector <int> tmp;

int main() {
    freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);


    for(int i = 2; i < N; i++) if (!p[i]) {
		int j = i;
		while (j < N) {
			if (!p[j]) p[j] = i;
			j += i;
		}
	}

    cin >> nt;
    while(nt--) {
        memset(d, 0, sizeof(d));
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                int val = (ll) a[i] * a[j] % 359999;
                d[val]++;
                tmp.pb(val);
              // cout << val << "\n";
            }

        ll ret = 0;
        ll kol = 0;

        for(int i = 1; i < N; i++) {

            if (i == 1)
                dp[i] = 1;
            else {
                if (p[i / p[i]] == p[i])
                    dp[i] = 0;
                else
                    dp[i] = -1 * dp[i / p[i]];
            }

		if (!dp[i]) continue;

            int j = i; kol = 0;
            while (j < N) {
                kol += d[j];
                j += i;
            }
            ret += kol * (kol - 1) * (kol - 2)  / 6 % mod * dp[i] % mod;
            ret %= mod;
            ret += kol * (kol - 1) / 2 % mod * dp[i] % mod;
            ll numPair = kol * (kol - 1) / 2 % mod * dp[i] % mod;
            ret += numPair * d[0] % mod;
            ret %= mod;
        }
/*
        int kq = 0;
        for (int i = 0; i < tmp.size(); i++)
            for (int j = 0; j < tmp.size(); j++)
                for (int k = 0; k < tmp.size(); k++)
                    if (__gcd(tmp[i], __gcd(tmp[j], tmp[k])) == 1) {
                            kq++;
                      //  cout << i << " " << j << " " << k << "\n";
                    }

        cout << kq % mod << "\n"; /**/

        ret += (ll)d[0] * d[1] % mod; /// pair
        ret += (ll) d[0] * (d[0] - 1) / 2 % mod * d[1] % mod;
        ret *= 6;
        ret += d[1]; /// 3 of 1
        ret %= mod;
        if (ret < 0) ret += mod;
        cout << ret << "\n";
    }
    /**/ return 0;
}
