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
#define MAXN 505
#define MAXE 1000001
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
int n, m, k;

ll sum(int x) {
    return ((ll)x * (x + 1) / 2);
}


ll getLen(int len, int x) {
   int dd = min(x - 1, len);
   int add = len - dd;
   return sum(dd) + (ll)add * (x - 1);
}


bool check(int x) {
    ll need = (ll)x * n;

    need -= getLen(k - 1, x);
    need -= getLen(n - k, x);

    return (need <= m);
}

int main() {
    //freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;

    int l = 2;
    int r = m;
    int ret = 1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            ret = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    cout << ret;
    /**/ return 0;
}
