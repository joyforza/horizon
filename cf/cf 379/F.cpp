#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
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
using namespace std;
int n;
ll a[N];
int b[N];
int c[N];


int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> d[i];
    ll sumAll = 0;
    for (int i = 1; i <= n; i++)
        sumAll += (b[i] + d[i]);

    if (sumAll % (2 * n) != 0) {
        cout << -1;
        return 0;
    }

    ll sum = sumAll / (2 * n);
    for (int i = 1; i <= n; i++) {
        a[i] = (b[i] + d[i]) - sum;
        if (a[i] % n != 0) {
            cout << -1;
            return 0;
        }
        a[i] = a[i] / n;
    }

    /**/ return 0;
}
