#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, ll>
#define ppp pair<pp, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 30
#define base 311097
#define maxN 100011
typedef long long ll;
typedef long double ld;
using namespace std;

pp A, B, C;

int mu(int x) {
    return x * x;
}

vector <pp> ret;

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> A.fi >> A.se;
    cin >> B.fi >> B.se;
    cin >> C.fi >> C.se;

    int AB = mu(A.fi - B.fi) + mu(A.se - B.se);
    int BC = mu(B.fi - C.fi) + mu(B.se - C.se);
    int AC = mu(A.fi - C.fi) + mu(A.se - C.se);

    {
        int x = (A.fi + C.fi) - B.fi;
        int y = (A.se + C.se) - B.se;
        ret.pb(mp(x, y));
    }

    {
        int x = (A.fi + B.fi) - C.fi;
        int y = (A.se + B.se) - C.se;
        ret.pb(mp(x, y));
    }

    {
        int x = (B.fi + C.fi) - A.fi;
        int y = (B.se + C.se) - A.se;
        ret.pb(mp(x, y));
    }

    cout << ret.size() << "\n";
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i].fi << " " << ret[i].se << "\n";
    /**/ return 0;
}
