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
#define N 30010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int a = 0, b = 0;
    int u, v;
    for (int i = 1; i <= n; i++) {
        cin >> u >> v;
        a += (u > v);
        b += (v > u);
    }
    if (a > b) cout << "Mishka";
    else
        if (a < b) cout << "Chris";
    else
        cout << "Friendship is magic!^^";
   /**/ return 0;
}
