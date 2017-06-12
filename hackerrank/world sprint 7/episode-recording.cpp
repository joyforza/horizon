#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define pp pair<int, int>
#define fi first
#define se second
using namespace std;
int f[123][2];
pp seg[123][2];
int n, nt;

int main() {
    freopen("in.in", "r", stdin);
    cin >> nt;
    while (nt--) {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> seg[i][0].fi >> seg[i][0].se >> seg[i][1].fi >> seg[i][1].se;

        f[1][0] = 1;
        f[1][1] = 1;
        for (int i = 2; i <= n; i++) {
            f[i][0] = i;
            f[i][1] = i;
            for (int j = 0; j <= n; j++)
                for (int k = 0; k < 2; k++)
                    if (seg[i][j].fi > seg[i - 1][k].se)
                        f[i][j] = min(f[i][j], f[i - 1][k]);
           // cout << f[i][0] << " " << f[i][1] << "\n";
        }

        int L = 1;
        int R = 1;
        for (int i = 1; i <= n; i++)
            for (int j = 0; j < 2; j++) {
               int cL = f[i][j];
               int cR = i;
               if (cR - cL > R - L) {
                   L = cL;
                   R = cR;
               }
        }
        cout << L << " " << R << endl;
    }
    return 0;
}
