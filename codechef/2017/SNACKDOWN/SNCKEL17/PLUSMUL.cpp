#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 100010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int nt;
int n;
int f[N];
int dp[N];
int sum;
int mul;

int pw(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1) {
            b--;
            ret = (ll) ret * a % mod;
        }
        else {
            b /= 2;
            a = (ll) a * a % mod;
        }
    }
    return ret;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);

    cin >> nt;
    while (nt--) {
        int x;
        cin >> n;
        cin >> x;
        mul = x;
        sum = x;
        dp[1] = x;
        int p2 = 1;

        for (int i = 2; i <= n; i++) {
            cin >> x;

            mul = ((ll)mul * x + (ll)p2 * x) % mod;

            p2 = (ll)p2 * 2 % mod;

            dp[i] = (sum + mul) % mod;

            sum = (sum + dp[i]) % mod;
        }
       // cout << "final = " << mul << "\n";

       // for (int i = 1; i <= n; i++) cout << dp[i] << " ";
       // cout << "***\n";

        cout << dp[n] << "\n";
    }
    /**/return 0;
}
