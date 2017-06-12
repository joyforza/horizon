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
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt;
int n;
int need;

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n;
        int ret = 0;
        need = 0;

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x == 1) {
                if (need > 0) {
                    ret += 100;
                }
            }
            else {
                ret += 100;
                need++;
            }
        }

      //  cout << need << "\n";

        ret += (need * 1000);
        cout << ret << "\n";
    }

    /**/ return 0;
}
