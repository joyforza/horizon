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
#define PI acos(-1)
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt;


int main() {
    freopen("25.in", "r", stdin);
    freopen("25.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        int P, x, y;
        cin >> P >> x >> y;
        bool ok = false;

        if (P > 0) {
            int lenV1 = (x - 50) * (x - 50) + (y - 50) * (y - 50);
            int lenV2 = 50 * 50;

            if (lenV1 <= 50 * 50) {
                if (x == 50 && y == 50) ok = true;
                else {
                    double gs = acos(50 * (y - 50) / (sqrt(lenV1) * 50)) * 180.0 / PI;

                    if (x == 50) gs = 180;
                    else
                    if (x < 50 && y < 50) gs += 180;
                    else
                        if (x < 50 && y >= 50) gs = 360 - gs;


                    if (gs <= P * 3.6)
                        ok = true;
                }
            }
        }
        cout << "Case #" << kk << ": " << (ok ? "black" : "white")<< "\n";
    }
    /**/ return 0;
}
