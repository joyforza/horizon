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
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, b, d;
int x;
int tot = 0;
int ret = 0;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> b >> d;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        if (x > b) continue;
        tot += x;
        if (tot > d) {
            ret++;
            tot = 0;
        }
    }
    cout << ret;
    /**/ return 0;
}
