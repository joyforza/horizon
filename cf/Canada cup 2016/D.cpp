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
    freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);

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
    int ret = n;

    ll pay = 0;
    int cnt = 0;
    ll curSum = 0;

    if (a.size() > 0 && money >= a[0].fi) ret = 1;

    int rnk = 0;
    for (int i = 0; i < a.size(); i++) {
        if (i == a.size() - 1) {
            if (a[i].fi > money) rnk++;
        }
        else
            if (a[i].fi != a[i + 1].fi && a[i].fi > money)
                rnk++;
    }

    cout << rnk << "\n";

    for (int i = 0; i < a.size(); i++) {

        ll nwVal = a[i].se - a[i].fi + 1;
        curSum += nwVal;

        if (i == a.size() - 1) {
            pay += money;
            money = 0;
        }
        else {

            if (a[i].fi == a[i + 1].fi) continue;

            ll add = max(0ll, money - a[i + 1].fi);
            pay += add;
            money -= add;
        }



        cnt++;

            if (quMax.empty() || (quMax.top() <= curSum)) {
                quMin.push(-curSum);
            }
            else {
                ll val = quMax.top();
                pay += val;
                quMax.pop();
                quMin.push(-curSum);
                quMin.push(val);
            }

            /// paying
            while (!quMin.empty()) {
                    ll val = -quMin.top();
                    if (val <= pay) {
                        cout << "paying" << "\n";
                        cout << "value: " << val << "\n";

                        pay -= val;
                        quMax.push(val);
                        quMin.pop();
                    }
                    else
                        break;
                }


          //  cout << a[i + 1].fi << "\n";
            if (cnt >= rnk) {
                cout << i << "\n";

                ret = min(ret, cnt + 1 - (int)quMax.size());
                cout << "at: " << cnt << " " << ret << "\n";
            }

            curSum = 0;
        }

    cout << ret;
    /**/ return 0;
}
