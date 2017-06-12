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
#define M (1 << 16) + 1
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
int a[N];
int nxt[N];
int last[N];

int compute(int l, int r) {
    if (l > r) return 0;
    int cur = l;
    int ret = 0;
    while (true) {
        if (a[cur] == 0) cur++;
        else
        if (nxt[cur] == -1) cur++;
        else {
            ret = max(ret, compute(cur + 1, nxt[cur] - 1));
            cur = nxt[cur];
        }
        if (cur > r) break;
    }
    return ret + 1;
}

int main() {
    freopen("art2.in", "r", stdin);
    freopen("art2.out", "w", stdout);
    ios::sync_with_stdio(false);
    memset(nxt, -1, sizeof(nxt));

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (last[a[i]] != -1) {
            int ls = last[a[i]];
            nxt[ls] = i;
        }

        last[a[i]] = i;
    }

    cout << compute(1, n);
    /**/ return 0;
}
