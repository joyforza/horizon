#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, pp>
#define pp3 pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 1010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;

bool f[55];
int lim[55];
int us[55];

int mask[55];

class TreeDistanceConstruction {
public:
    TreeDistanceConstruction(){}
    vector <int> construct(vector <int> d) {
        vector <int> ret;
        vector <pp> d2;

        for (int i = 0; i < d.size(); i++)
            d2.pb(mp(d[i], i));

        sort(d2.begin(), d2.end());

        int n = d.size();

        if (d2[n - 1].fi != d2[n - 2].fi) {
            return ret;
        }

        f[n - 1] = true;
        f[n - 2] = true;
        int maxLen = d2[n - 1].fi;

        if (maxLen + 1 > n) {
            return ret;
        }



        int remain = n - 2;

        vector <pp> mat;
        mask[0] = d2[n - 1].se;
        mask[maxLen] = d2[n - 2].se;

        //cout << mask[0] << "\n";
        //cout << mask[maxLen] << "\n";

        for (int i = 1; i < maxLen; i++) {
            int x = max(maxLen - i, i);
            bool ok = false;
            for (int j = 0; j < n; j++)
                if (f[j] == false && d2[j].fi == x) {
                    f[j] = true;
                    ok = true;
                    remain--;
                    mask[i] = d2[j].se;
                   // cout << "mask " << j << "\n";
                    break;
                }

            if (!ok) {
                ret.clear();
                return ret;
            }
            mat.pb(mp(mask[i], x));
        }

        for (int i = 0; i < maxLen; i++) {
            ret.pb(mask[i]);
            ret.pb(mask[i + 1]);
        }

        for (int i = 0; i < n; i++)
        if (f[i] == false) {
            bool ok = false;
            for (int j = 0; j < mat.size(); j++)
            if (mat[j].se + 1 == d2[i].fi && mat[j].se + 1 <= maxLen) {
                int cur = mat[j].fi;

                ret.pb(cur);
                ret.pb(d2[i].se);

                mat.pb(mp(d2[i].se, mat[j].se + 1));
                ok = true;
                break;
            }
            if (!ok) {
                ret.clear();
                return ret;
            }
        }

        return ret;
    }
};

int main() {
   // freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    vector <int> ts;
    ts.pb(3);
    ts.pb(2);
    ts.pb(2);
    ts.pb(3);

    TreeDistanceConstruction a;
    a.construct(ts);

    /**/return 0;
}
