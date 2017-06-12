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
int n;
int a[N];
int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int minval = inf;
    int dem = 0;
    for (int i = 1; i < n; i++)
    if (a[i + 1] - a[i] < minval) {
        minval = a[i + 1] - a[i];
        dem = 1;
    }
    else
        if (a[i + 1] - a[i] == minval) dem++;
    cout << minval << " " << dem;

    /**/ return 0;
}
