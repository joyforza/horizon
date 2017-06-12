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
#define N 501
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
ll n;
bool isSquare(ll n) {
    if (n <= 0) return false;
    ll x = sqrt(n);
    return (x * x == n);
}


int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    if (n % 2 == 0) {
        for (int i = 1; i <= sqrt(n); i++)
        if (n % (2 * i) == 0) {
            ll p = i;
            ll q = n / (2 * i);


            if (p < q) swap(p, q);
            ll y = p * p - q * q;
            ll z = p * p + q * q;


            if (y > 0) {
                cout << y << " " << z << endl;
                return 0;
            }
        }
    }
    else {
        /// case 1:
        for (ll i = 1; i <= sqrt(n); i++) {
            ll x = i * i;
            ll y = n * n - x;

            if (isSquare(y)) {
                cout << sqrt(x) << " " << sqrt(y);
                return 0;
            }
        }
        /// case 2:
        for (ll i = 1; i <= sqrt(n); i++)
        if (n % i == 0) {
            ll sum = n / i;
            ll sub = i;
            if (sum < sub) swap(sum, sub);

            ll p = (sum + sub) / 2;
            ll q = sum - p;
            if (p > 0 && q > 0 && p > q) {
                ll x = 2 * p * q;
                ll z = p * p + q * q;
                cout << x << " " << z << endl;
                return 0;
            }
        }
    }
    cout << -1;
    /**/ return 0;
}
