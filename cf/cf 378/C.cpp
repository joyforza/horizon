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
using namespace std;
int n, m, x;
int a[555];
vector <int> b[555];
int c[555];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    bool ok = true;
    cin >> m;
    int last = 1;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        for (int j = last; j <= n; j++) {
            if (x >= a[j]) {
                x -= a[j];
                b[i].pb(j);
                if (x == 0) {
                    last = j + 1;
                    break;
                }
            }
            else {
                if (x > 0) {
                    ok = false;
                    break;
                }
            }
        }
    }
    if (last != n + 1) ok = false;



    if (!ok) cout << "NO";
    else {

        int cur = 0;
        for (int i = 1; i <= m; i++) {
            if (b[i].size() > 1) {
                int best = a[b[i][0]];
                int cnt = 1;

                for (int j = 1; j < b[i].size(); j++)
                    if (best == a[b[i][j]]) cnt++;

                if (cnt == b[i].size()) {
                    cout << "NO";
                    return 0;
                }
            }
        }

        cout << "YES\n";
        for (int i = 1; i <= m; i++) {
        if (b[i].size() > 1) {
                int best = a[b[i][0]];
                for (int j = 1; j < b[i].size(); j++)
                    best = max(best, a[b[i][j]]);
                int n = b[i].size();

                for (int j = 1; j <= n; j++)
                    c[j] = a[b[i][j - 1]];

                while (n > 1) {
                    for (int j = 1; j < n; j++)
                        if (c[j] == best) {
                            cout << j + cur << " R\n";
                            best += c[j + 1];
                            c[j] = best;
                            for (int k = j + 1; k < n; k++)
                                c[k] = c[k + 1];
                            n--;
                            break;
                        }
                        else
                        if (c[j + 1] == best) {
                            cout << j + 1 + cur << " L\n";
                            best += c[j];
                            c[j + 1] = best;
                            for (int k = j; k < n; k++)
                                c[k] = c[k + 1];
                            n--;
                            break;
                        }
                }
            }
            cur ++;
        }
    }
    /**/ return 0;
}
