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
int d[N];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    int cnt = 0;
    int ret = 0;
    for (int i = 1; i <= 2 * n; i++) {
        int x;
        cin >> x;
        if (d[x] == 0) {
            d[x]++;
            cnt++;
        }
        else {
            d[x]--;
            cnt--;
        }
        ret = max(ret, cnt);
    }

    cout << ret;
    /**/ return 0;
}

