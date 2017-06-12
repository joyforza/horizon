#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, ll>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m, k;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    if (n % 2 == 0) {
        cout << "Marsel";
        return 0;
    }

    int best = inf;

    for (int i = 1; i <= m / i; i++)
    if (m % i == 0){
        if (i >= k) best = min(best, i);
        if (m / i >= k) best = min(best, m / i);
    }

    if (best == inf) {
        cout << "Marsel";
        return 0;
    }

    for (int i = 1; i <= best / i; i++)
    if (best % i == 0) {
        if (i >= k) {
            cout << "Marsel";
            return 0;
        }

        if (best / i >= k) {
            cout << "Marsel";
            return 0;
        }
    }

    cout << "Timur";
    /**/ return 0;
}
