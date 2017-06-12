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
#define N 1000010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

bool play1(int x, int y) {
    if (x % 2 != 0 && y % 2 != 0) return false;
    return true;
}

bool play2(int x, int y) {
    if (x % 2 == 0 && y % 2 == 0) return true;
    return false;
}

int nt;
int n, m, p, k;

long double nhan(long double x, long double y) {
    if (x * y < esp) {
        return (x / 2);
    }
    return x * y;
}

long double sw[N];
long double sl[N];

int main() {
   //  freopen("in.in", "r", stdin);
  //  freopen("in2.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;

    while (nt--) {
        cin >> n >> m >> p >> k;
        long double win = 0;
        // probability to win
        win += 0.5 * play1(n, m);
        win += 0.5 * play2(n, m);


       // cout << win << "\n";

        long double lose = (1 - win);
        sw[0] = 1;
        sl[0] = 1;
        for (int i = 1; i <= k; i++) {
            sw[i] = sw[i - 1] * win;
            sl[i] = sl[i - 1] * lose;
        }

        long double ret = sw[k];
        int dem = 0;

        long double com = 1;
        for (int i = k - 1; i >= p; i--) {
            dem++;
            com = nhan(com * (i + 1), (long double) 1.0 / dem);
            ret += nhan(com, sw[i] * sl[k - i]);
        }

         if (win < esp) ret = 0;
        if (p == 0) {
            if (k == 0) ret = 0;
            else
                ret = 1;
        }

       printf("%.6lf\n", (double)ret);
    }

    /**/ return 0;
}

