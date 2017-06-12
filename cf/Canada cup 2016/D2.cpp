#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, ll>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 10010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
vector <pp> a;
ll money;

bool cmp(pp a, pp b) {
    return (a.fi > b.fi);
}

priority_queue <ll> quMax;
priority_queue <ll> quMin;

int main() {

   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x, y;
        cin >> x >> y;
        if (i == 1) money = x;
        else {
            a.pb(mp(x, y));
        }
    }

    sort(a.begin(), a.end(), cmp);

    ll pay = 0;

    int rnk = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].fi > money) rnk++;
    }
    ll mon = money;

    int ret = rnk + 1;

    for (int i = 0; i < a.size(); i++) {

        ll nwVal = a[i].se - a[i].fi + 1;

        if (i == a.size() - 1) {
            pay += money;
            money = 0;
        }
        else {
            ll add = max(0ll, money - a[i + 1].fi);
            pay += add;
            money -= add;
        }


        if (quMax.empty() || (quMax.top() <= nwVal)) {
                quMin.push(-nwVal);
            }
            else {
                ll val = quMax.top();
                pay += val;
                quMax.pop();
                quMin.push(-nwVal);
                quMin.push(val);
            }

            /// paying
            while (!quMin.empty()) {
                    ll val = -quMin.top();
                    if (val <= pay) {
                        pay -= val;
                        quMax.push(val);
                        quMin.pop();
                    }
                    else
                        break;
                }

            if (i + 1 >= rnk)
            if ((i == a.size() - 1 && a[i].fi > 0) || (i < a.size() - 1 && a[i + 1].fi < a[i].fi)) {
                ret = min(ret, i + 2 - (int)quMax.size());
              //  cout << i << " " << ret << "\n";
                if (mon == 133242 && ret == 414) {
                    cout << "at: " << i + 1 << "\n";
                    cout << "del: " << quMax.size() << "\n";
                    cout << "queue Min: " << quMin.size() << "\n";
                    cout << "remain money: " << pay << "\n";
                    cout << "rnk = " << rnk << "; " << a[i].fi << " " << a[i + 1].fi << "\n";
                    break;
                }
            }

        }

    cout << ret;

    /**/ return 0;
}
