#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 1010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt;
int R, O, Y, G, B, V;
int n;
vector <pp> tmp;
vector <pp> rr;

char getS(int x) {
    if (x == 1) return 'R';
    if (x == 2) return 'Y';
    return 'B';
}


void solve(int a, int b, int c) {

  //  cout << a << " " << b << " " << c << "\n";
    rr.clear();

    tmp.clear();
    tmp.pb(mp(a, 1));
    tmp.pb(mp(b, 2));
    tmp.pb(mp(c, 3));
    sort(tmp.begin(), tmp.end());
    a = tmp[0].fi;
    b = tmp[1].fi;
    c = tmp[2].fi;
    int ax = tmp[0].se;
    int bx = tmp[1].se;
    int cx = tmp[2].se;

    if (a + b < c) {
        cout << "IMPOSSIBLE\n";
    //    cout << a << " " << b << " " << c << "\n";
        return;
    }
  //  cout << a << " " << b << " " << c << "\n";

    string ret = "";
    for (int i = 1; i <= c; i++) {
        if (b > 0) {
            rr.pb(mp(cx, bx));
            b--;
        }
        else
        if (a > 0) {
            rr.pb(mp(cx, ax));
            a--;
        }
    }
    for (int i = 0; i < rr.size(); i++) {
        ret = ret + getS(rr[i].fi);
        if (a > 0) {
            ret = ret + getS(ax);
            a--;
        }
        ret = ret + getS(rr[i].se);
        if (a > 0) {
            ret = ret + getS(ax);
            a--;
        }
    }
    cout << ret << "\n";


    bool ok = true;
    for (int i = 0; i < ret.size() - 1; i++)
        if (ret[i] == ret[i + 1]) {
            ok = false;
        }

    if (ret[0] == ret[ret.size() - 1]) ok = false;
    if (ok == false) {
        cout << "**************\n";
    }
}

int main() {
    freopen("B.in", "r", stdin);
    freopen("B.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        cin >> n >> R >> O >> Y >> G >> B >> V;
        cout << "Case #" << kk << ": ";


        if (O == 0 && G == 0 && V == 0) {
            solve(R, Y, B);
        }
    }
    /**/ return 0;
}
