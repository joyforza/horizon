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
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;


int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    while(nt--) {
        ll C, D, L;
        cin >> C >> D >> L;
        if (L % 4 != 0) puts("no");
        else {
            L /= 4;
            int minFoot = D + max(0ll, C - 2 * D);
            int maxFoot = D + C;
            if (L >= minFoot && L <= maxFoot) puts("yes");
            else
                puts("no");
        }
    }
    /**/ return 0;
}
