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
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
char c[] = {'R', 'O', 'Y', 'B', 'G', 'I', 'V'};
int d[123];
int n;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(d, -1, sizeof(d));
    cin >> n;

    for (int i = 0; i < 7; i++)
        d[i] = i;
    for (int i = 7; i <= n; i++) {

        for (int j = 0; j < 7; j++) {
            bool ok = true;
            for (int k = i - 3; k <= i + 3; k++) {
                int pos = k;
                if (pos < 0) pos += n;
                if (pos >= n) pos -= n;
                if (d[pos] == j) ok = false;
            }

            if (ok) {
                d[i] = j;
                break;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << c[d[i]];

    /**/ return 0;
}
