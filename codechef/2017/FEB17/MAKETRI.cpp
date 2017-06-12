#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, ll>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 1000010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
ll L, R;
ll a[N];
ll ret = 0;

void addSeg(ll u, ll v) {
    u = max(u, L);
    v = min(v, R);
    if (u <= v) {
        ret += (v - u + 1);
    }
}

vector <pp> rr;
bool del[N];

bool inside(pp a, pp b) {
    return (a.fi <= b.fi && b.fi <= a.se);
}

int main() {
   // freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
 //   int nt;
  //  cin >> nt;
  //  while (nt--) {

    ret = 0;
    cin >> n >> L >> R;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);

    ll curL = -1;
    ll curR = -1;

    for (int i = 2; i <= n; i++) {
        ll tmpL = a[i] - a[i - 1] + 1;
        ll tmpR = (a[i - 1] - 1 > R - a[i] ? R : a[i - 1] + a[i] - 1);
        rr.pb(mp(tmpL, tmpR));
    }

    sort(rr.begin(), rr.end());
    for (int i = 0; i < rr.size(); i++)
    if (del[i] == false) {
        for (int j = i + 1;  j < rr.size(); j++)
            if (inside(rr[i], rr[j])) {
                rr[i].se = max(rr[i].se, rr[j].se);
                del[j] = true;
            }
            else
                break;
    }

    for (int i = 0; i < rr.size(); i++)
    if (del[i] == false) {
        addSeg(rr[i].fi, rr[i].se);
    }

    cout << ret << "\n";

  //  }
    /**/ return 0;
}
