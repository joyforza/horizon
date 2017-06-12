#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 50100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int a[555];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    while (nt--) {
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll ret = (ll)inf * inf;
        for (int i = 1; i < n; i++)
            for (int j = i + 1; j <= n; j++)
                ret = min(ret, ((ll)a[i] / __gcd(a[i], a[j])) * a[j]);
        cout << ret << "\n";
    }
    /**/ return 0;
}
