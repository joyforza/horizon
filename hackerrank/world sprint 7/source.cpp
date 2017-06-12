#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pp pair<int, int>
typedef long long ll;
using namespace std;
map <int, int> M;
int n, m, k;
vector<pp> a[1010];
vector<pp> tmp;
int cnt = 0;

bool cmp(pp x, pp y) {
    return (x.fi < y.fi || (x.fi == y.fi && x.se > y.se));
}

int main() {
 //   freopen("in.in", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++) {
        int row, l, r;
        cin >> row >> l >> r;
        if (!M.count(row)) {
            M[row] = ++cnt;
        }

        a[M[row]].pb(mp(l, r));
    }



    ll sub = 0;
    for (int i = 1; i <= cnt; i++) {
        tmp.clear();
        for (int j = 0; j < a[i].size(); j++) tmp.pb(a[i][j]);
        sort(tmp.begin(), tmp.end(), cmp);

        int L = tmp[0].fi;
        int R = tmp[0].se;

        for (int j = 1; j < tmp.size(); j++)
            if (tmp[j].fi > R) {
                sub += (R - L + 1);
                L = tmp[j].fi;
                R = tmp[j].se;
            }
            else
                R = max(R, tmp[j].se);

        sub += (R - L + 1);
    }

    cout << (ll) m * n - sub;
    return 0;
}
