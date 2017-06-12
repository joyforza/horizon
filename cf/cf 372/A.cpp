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
int n, c;
int u, v;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> c;
    cin >> u;
    int w = 1;

    for (int i = 2; i <= n; i++) {
        cin >> v;
        if (v - u <= c) w++;
        else
            w = 1;

        u = v;
    }

    cout << w;
    /**/ return 0;
}
