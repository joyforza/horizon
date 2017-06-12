#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define N 100010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int nt;
vector <ppp> a;
vector <ppp> b;
vector <pp> c;
vector <pp> tmp;
int n, m, k;

bool cmp(pp x, pp y) {
    if (x.fi != y.fi) return x.fi < y.fi;
    return (x.se < y.se);
}

int getNeed() {
    if (c.size() == 0) return inf; /// no way
    tmp.clear();
    sort(c.begin(), c.end(), cmp);
    c.pb(mp(-1, -1));

    for (int i = 0; i < c.size() - 1; i++)
        if (c[i].fi != c[i + 1].fi) tmp.pb(c[i]);

    if (tmp[0].fi > (n - k) / 2 + 1) return inf;

    int R = tmp[0].se;
    int ans = 1;
    int pos = 1;

    while (true) {

        if (R >= (n - k) / 2 + 1 + k) break;

        int tmpR = R;
        int newpos = pos;

        for (int i = pos; i < tmp.size(); i++) {
            if (tmp[i].fi <= R) {
                tmpR = max(tmpR, tmp[i].se);
            }
            else {
                newpos = i;
                break;
            }
        }

        if (tmpR > R) {
            ans++;
            R = tmpR;
        }

        if (newpos == pos) break;
    }

    if (R < (n - k) / 2 + 1 + k) return inf;
    return ans;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        a.clear();
        b.clear();
        cin >> n >> k >> m;
        for (int i = 1; i <= m; i++) {
            int sx, sy;
            int fx, fy;
            cin >> sx >> sy >> fx >> fy;
            if (sx == fx) {
                if (sy > fy) swap(sy, fy);
                a.pb(mp(sx, mp(sy, fy + 1)));
            }
            else {
                if (sx > fx) swap(sx, fx);
                b.pb(mp(sy, mp(sx, fx + 1)));
            }
        }
        int L = (n - k) / 2 + 1;
        int R = L + k;

        c.clear();
        int ret = 0;
        for (int i = 0; i < a.size(); i++) {
            int l = a[i].se.fi;
            int r = a[i].se.se;
            if (r <= L || l >= R) continue;
            l = max(l, L);
            r = min(r, R);
            c.pb(mp(l, r));
        }

        for (int i = 0; i < b.size(); i++) {
            int l = b[i].fi;
            int r = b[i].fi + 1;
            if (r <= L || l >= R) continue;
            c.pb(mp(l, r));
        }

        ret += getNeed();
        c.clear();

        for (int i = 0; i < a.size(); i++) {
            int l = a[i].fi;
            int r = a[i].fi + 1;
            if (r <= L || l >= R) continue;
            c.pb(mp(l, r));
        }

        for (int i = 0; i < b.size(); i++) {
            int l = b[i].se.fi;
            int r = b[i].se.se;
            if (r <= L || l >= R) continue;
            l = max(l, L);
            r = min(r, R);
            c.pb(mp(l, r));
        }

        ret += getNeed();

        if (ret >= inf) cout << -1 << "\n";
        else
            cout << ret << "\n";
    }
    /**/return 0;
}
