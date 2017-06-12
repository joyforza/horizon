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
#define N 100005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
ll en[N];
ll st, fn, t;
ll a[N];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> st >> fn >> t;
    cin >> n;

    if (n == 0) {
        cout << st << "\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);

    /// END
    en[1] = max(a[1] + t, st + t);

    for (int i = 2; i <= n; i++) {
        en[i] = max(en[i - 1] + t, a[i] + t);
    }

    /// ALL
    ll pos = min(st, a[1] - 1);
    ll w = st - pos;

 //   if (pos == st) {
  //      cout << st;
   //     return 0;
    //}

    a[n + 1] = oo;
    for (int i = 1; i <= n; i++)
    if (a[i] + 1 < a[i + 1]) {
       if (en[i] < a[i + 1]) {
            ll newpos = en[i];
            if (newpos + t <= fn) {
                cout << newpos;
                return 0;
            }
        }
        else {
            ll newpos = a[i + 1] - 1;
            ll neww = en[i] - newpos;
            if (neww < w && newpos + t <= fn) {
                w = neww;
                pos = newpos;
            }
        }
    }

    cout << pos;
    /**/ return 0;
}

