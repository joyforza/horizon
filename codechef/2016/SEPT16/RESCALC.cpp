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
#define N 256
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int nt;
int n, m, x;
int d[12];

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n;
        int maxval = -1;
        int win = -1;
        int nwin = 1;

        for (int i = 1; i <= n; i++) {
            cin >> m;
            memset(d, 0, sizeof(d));
            for (int j = 1; j <= m; j++) {
                cin >> x;
                d[x - 1]++;
            }
            sort(d, d + 6);
            int sc = m;
            sc += (d[2] - d[1]);
             sc += (d[1] - d[0]) * 2;
            sc += d[0] * 4;

            if (sc > maxval) {
                maxval = sc;
                win = i;
                nwin = 1;
            }
            else
                if (sc == maxval)
                    nwin++;
        }


        if (nwin > 1) cout << "tie\n";
        else {
            if (win == 1)
                cout << "chef\n";
            else
                cout << win << endl;
        }
    }

    /**/ return 0;
}
