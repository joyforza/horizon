#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, ll>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 200010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int a[N];
int A, B, h, w, n;
map<pp, int> M;

bool cmp(int x, int y) {
    return x > y;
}

int Make(ll h, ll w, int i) {
    cout << h << " " << w << "\n";

    if (A <= h && B <= w) return 0;
    if (i > n) return inf;
    if (i == n) return 0;

    if (M.count(mp(h, w))) return M[mp(h, w)];
    int ret = inf;
    if (h < A) ret = min(ret, 1 + Make(min(100001ll, h * a[i]), w, i + 1));
    if (w < B) ret = min(ret, 1 + Make(h, min(10001ll, w * a[i]), i + 1));
    ret = min(ret, Make(h, w, i + 1));
    M[mp(h, w)] = ret;
    return ret;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> A >> B >> h >> w >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1, cmp);

    n = min(n, 40);

    int ret = Make(h, w, 1);
    swap(A, B);
    M.clear();



    ret = min(ret, Make(h, w, 1));
    if (ret == inf) cout << -1;
    else
        cout << ret;

    /**/return 0;
}
