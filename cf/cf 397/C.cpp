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
#define N 50005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int k, a, b;

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> k >> a >> b;
    if (a == 0 || b == 0) {
        int c = max(a, b);
        if (c % k != 0) {
            cout << -1;
        }
        else
            cout << (c / k);
    }
    else {
        int cnt = (a / k) + (b / k);
        int ra = (a % k);
        int rb = (b % k);

        if (ra > 0 && (b / k == 0)) {
            cout << -1;
            return 0;
        }

        if (rb > 0 && (a / k == 0)) {
            cout << -1;
            return 0;
        }
        cout << cnt;
    }
    /**/ return 0;
}

