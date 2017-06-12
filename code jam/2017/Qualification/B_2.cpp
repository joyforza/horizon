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
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt;
ll n;
int d[22];
int d2[22];

bool isGood(int x) {
    int ls = inf;
    while (x > 0) {
        if (x % 10 > ls) return false;
        ls = x % 10;
        x /= 10;
    }
    return true;
}

int main() {
    freopen("B_3.in", "r", stdin);
    //freopen("B_2.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int ic = 0;
    cin >> nt;
    for (int kk = 1; kk <= nt; kk++) {
        cin >> n;
        int m = 0;
        int sn = n;

        while (n > 0) {
            d[++m] = n % 10;
            n /= 10;
        }
        int pos = m;
        for (int i = 1; i <= m; i++) {
            d2[i] = d[pos];
            pos--;
        }
        for (int i = 1; i <= m; i++) d[i] = d2[i];

        bool ok = true;
        for (int i = 2; i <= m; i++) {
           if (d[i] < d[i - 1]) {
               int pos = i - 1;
               for (int j = i - 2; j >= 1; j--)
                    if (d[j] == d[pos]) pos = j;
               if (d[pos] == 1) ok = false;
               else
                    d[pos]--;

               for (int j = pos + 1; j <= m; j++)
                    d[j] = 9;
               break;
           }
        }

        if (!ok) {
            m--;
            for (int i = 1; i <= m; i++) d[i] = 9;
        }
        /** checker **/
        int val1 = 0;
        int val2 = 0;
        for (int i = 1; i <= m; i++) val1 = val1 * 10 + d[i];
        for (int i = sn; i >= 1; i--)
        if (isGood(i)) { val2 = i; break; }
        if (val1 != val2) {
                ic++;
            cout << "INCORRECT!!!" << "\n";
        }
        else
            cout << "AC\n";

    }
    cout << "FAILED: " << ic << " testcase(s)";
    /**/ return 0;
}
