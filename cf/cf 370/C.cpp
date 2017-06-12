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
int fn, st;
map <ppp, int> M;

bool check(int x, int y, int z) {
    return (x + y > z && x + z > y && y + z > x);
}

int dp(int x, int y, int z) {

  //  cout << x << " " << y << " " << z << "\n";

    if (x == fn && y == fn && z == fn) return 0;

    if (M.count(mp(mp(x, y), z)))
        return M[mp(mp(x, y), z)];

    int ret = inf;

    int l = fn;
    int r = x;
    int nx = x;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid, y, z)) {
            nx = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }


    if (nx != x)
        ret = min(ret, 1 + dp(nx, y, z));

    l = fn;
    r = y;
    int ny = y;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(x, mid, z)) {
            ny = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    if (ny != y)
        ret = min(ret, 1 + dp(x, ny, z));

    l = fn;
    r = z;
    int nz = z;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(x, y, mid)) {
            nz = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }

    if (nz != z)
        ret = min(ret, 1 + dp(x, y, nz));

    M[mp(mp(x, y), z)] = ret;
    return ret;
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> st >> fn;
    cout << dp(st, st, st) << "\n";
    /**/ return 0;
}
