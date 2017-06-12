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


int main() {
    freopen("in.in", "w", stdout);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);

    int nt = 20;
    int maxn = 10;
    cout << nt << "\n";

    for (int i = 1; i <= nt; i++) {
        int l = (rand() % 10) + 1;
        int r = l + (rand() % 5);

        cout << maxn << " " << l << " " << r << "\n";

        for (int j = 1; j <= maxn; j++)
            cout << (rand() % 10) + 1 << " ";

        cout << "\n";
    }
    /**/ return 0;
}
