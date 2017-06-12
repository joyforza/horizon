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
#define N 300005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m, k;
int s[10000011];
pp a[1000010];


int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        x++;
        s[x]++;
    }

    int add = 0;
    for (int i = 10000000; i >= 1; i--) {
        s[i] += add;
        add = 0;
        if (s[i] >= k) {
            add += (s[i] - k);
        }
    }
    if (add > 0) {
        printf("-1");
        return 0;
    }

    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        x++;
        s[x]++;
        a[i] = mp(x, i);
    }
    sort(a + 1, a + m + 1);

    add = 0;
    for (int i = 10000000; i >= 1; i--) {
        s[i] += add;
        add = 0;
        if (s[i] >= k) {
            add += (s[i] - k);
        }
    }
    int ret = m - add;
    printf("%d\n", ret);
    for (int i = add + 1; i <= m; i++)
        printf("%d ", a[i].se);

    /**/ return 0;
}
