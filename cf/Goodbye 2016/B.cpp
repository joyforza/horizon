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
#define N 100010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    int root = 0;
    bool ok = true;

    for (int i = 1; i <= n; i++) {
        int x;
        string s;
        cin >> x >> s;

        if (root == 0) {
            if (s != "South") {
                ok = false;
                break;
            }
        }
        else
        if (root == 20000) {
            if (s != "North") {
                ok = false;
                break;
            }
        }

        ///
        if (s == "South") {
            int sg = 1;

            while (x--) {
                root += sg;
                if (root == 20000) sg -= sg;
                if (root == 0) sg = -sg;
            }
        }

        if (s == "North") {
            int sg = -1;

            while (x--) {
                root += sg;

                if (root == 0) sg = -sg;
                if (root == 20000) sg = -sg;
            }
        }
    }

    if (root != 0) ok = false;
    puts(ok ? "YES" : "NO");
    /**/ return 0;
}
