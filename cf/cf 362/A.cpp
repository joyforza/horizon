#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 10010
typedef long long ll;
typedef long double ld;
using namespace std;
int t, s, x;

int main() {
//    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> t >> s >> x;
    if (x == t) {
        cout << "YES";
        return 0;
    }

    int d = (x - t) / s;
    if (d > 0) {
        if (x == t + d * s) {
            cout << "YES";
            return 0;
        }
    }

    d = (x - 1 - t) / s;
    if (d > 0) {
        if (x == t + d * s + 1) {
                cout << "YES";
        return 0;
        }
    }
    cout << "NO";

   /**/ return 0;
}
