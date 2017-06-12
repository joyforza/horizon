#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 10000000000000001ll
#define mod 10007
#define N 100010
#define lg 18
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int a[N];
int n;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        ret = ret + (ll)a[i] * a[n - i + 1] % mod;
        ret %= mod;
    }
    cout << ret;
    /**/ return 0;
}
