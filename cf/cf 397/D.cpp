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
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
int f[N];
int g[N];
int h[N];
int ass[N];

int main() {
   // freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> f[i];
    for (int i = 1; i <= n; i++) {

        if (g[f[i]] == 0) {
            g[f[i]] = i;
            ass[f[i]] = i;
        }
    }

    for (int i = 1; i <= n; i++)
    if (g[i] > 0) {
     //   cout << "h[ " << g[i] << " ] == " << f[i] << "\n";
        h[g[i]] = f[i];
    }

    for (int i = 1; i <= n; i++)
    if (g[i] == 0) {
        g[i] =  ass[f[i]] ;
    }

    int pos = n;
    for (int i = n; i >= 1; i--)
    if (h[i] > 0) {
        pos = i;
        break;
    }

    for (int i = 1; i <= pos; i++)
    if (h[i] == 0) {
        cout << -1;
        return 0;
    }

    //for (int i =1 ; i <= n; i++)
    //    cout << g[i] << "\n";

    for (int i = 1; i <= n; i++) {
        if (h[g[i]] != f[i]) {
            cout << -1;
            return 0;
        }
    }

    for (int i = 1; i <= pos; i++) {
        if (g[h[i]] != i) {
            cout << -1;
            return 0;
        }
    }
    cout << pos << "\n";
    for (int i = 1; i <= n; i++) cout << g[i] << " ";
    cout << "\n";
    for (int i = 1; i <= pos; i++) cout << h[i] << " ";
    /**/ return 0;
}

