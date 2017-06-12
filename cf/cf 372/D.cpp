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
#define N 100010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
ll x;

bool isSquare(ll x) {
    ll k = sqrt(x);
    return (k * k == x);
}

int main() {
    freopen("ou.ou", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int n = 999;

    ll cur = 2;
    for (int i = 1; i <= n; i++) {
        cin >> x;
      //  assert(x <= 1000000000000000000);
        cur = (cur + i * x);
        if (isSquare(cur) == false) {
            cout << "WAAAAAAA" << i << "\n";

            return 0;
        }
        cur = sqrt(cur);
        if (cur % (i + 1) != 0) {
            cout << "WAAAAAA" << i << "\n";
            return 0;
        }
    }
    cout << "Accepted!";
    /**/ return 0;
}
