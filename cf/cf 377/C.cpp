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
ll a[4];
ll b[4];
int d[] = {1, 2, 3, 1, 2, 3};

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> a[1] >> a[2] >> a[3];
    ll ret = -1;
    for (int i = 0; i < 6; i++)
    for (int j = i; j < 6; j++) {
        ll ans = 0;

        b[1] = a[1];
        b[2] = a[2];
        b[3] = a[3];
        for (int k = i; k <= j; k++) {
            if (b[d[k]] > 0) b[d[k]]--;
            else
                ans++;
        }

        ll dm = max(max(b[1], b[2]), b[3]);
        ans = ans + (dm - b[1]) + (dm - b[2]) + (dm - b[3]);
        if (ret == -1) ret = ans;
        else
            ret = min(ret, ans);
    }

    cout << ret;
    /**/ return 0;
}
