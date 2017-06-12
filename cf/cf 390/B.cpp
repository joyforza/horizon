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
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
string s[5];

int cnt(int x, int y) {
    if (x < 0 || x >= 4) return 1000;
    if (y < 0 || y >= 4) return 1000;
    if (s[x][y] == 'o') return 1000;
    if (s[x][y] == '.') return 0;
    return 1;
}

bool check(int x, int y) {

    int d1 = cnt(x - 1, y - 1) + cnt(x, y) + cnt(x + 1, y + 1);
    int d2 = cnt(x - 1, y + 1) + cnt(x, y) + cnt(x + 1, y - 1);
    int d3 = cnt(x - 1, y) + cnt(x, y) + cnt(x + 1, y);
    int d4 = cnt(x, y - 1) + cnt(x, y) + cnt(x, y + 1);

    return (d1 == 2 || d2 == 2 || d3 == 2 || d4 == 2);
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    for (int i = 0; i < 4; i++) cin >> s[i];
    bool ok = false;

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            ok |= check(i, j);

    if (ok) cout << "YES";
    else
        cout << "NO";

    /**/ return 0;
}
