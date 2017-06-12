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
#define N 100010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int a[123];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1) {
        if (a[1] == 0) cout << "UP";
        else
            if (a[1] == 15) cout << "DOWN";
        else
            cout << -1;
    }
    else {
        if (a[n] - a[n - 1] > 0) {
            if (a[n] == 15) cout << "DOWN";
            else
                cout << "UP";
        }
        else {
            if (a[n] == 0) cout << "UP";
            else
                cout << "DOWN";
        }
    }

    /**/ return 0;
}
