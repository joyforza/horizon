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
#define N 123
#define base 311097
#define M 10000001
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int a[N];
bool f[N];
int id[N];
int sum[N];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int cnt = 0;
    for (int i = 1; i <= n; i++)
    if (f[i] == false) {

        cnt++;
        f[i] = true;

        int sv = i;
        int cur = i;
        id[i] = cnt;

       // cout << cur << "\n";

        int dem = 1;
        while (true) {
            cur = a[cur];

           // cout << "new = " << cur << "\n";

            if (f[cur]) {
                if (cur != sv) {
                    cout << -1;
                    return 0;
                }
                sum[cnt] = dem;
                break;
            }
            f[cur] = true;
            id[cur] = cnt;
            dem++;
        }
    }

    int ret = 0;
    for (int i = 1; i <= n; i++) {
            ret = max(ret, sum[id[i]]);
    }

    cout << ret;
    /**/ return 0;
}
