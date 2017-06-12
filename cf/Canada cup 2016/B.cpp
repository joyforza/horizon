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
#define N 10010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;

int d[12];
ll n;
char c;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    d[0] = 4;
    d[1] = 5;
    d[2] = 6;
    d[3] = 3;
    d[4] = 2;
    d[5] = 1;
    scanf("%I64d%c", &n, &c);

    ll m = n;
    if (n % 4 == 0 || n % 4 == 3) {
            m -= 2;
    }

    ll ret = m - 1;

    ret += ((m / 4) * 2 * 6) + d[c - 'a'];

    //cout << ret << "\n";

    if (n % 4 == 2 || n % 4 == 0)
        ret += 6;


    cout << ret;
    /**/ return 0;
}
