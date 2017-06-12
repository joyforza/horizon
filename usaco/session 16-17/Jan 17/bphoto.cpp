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
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
int n;
int a[N];
vector <int> c;
map<int, int> M;
int T[N];
int L[N], R[N];

int get(int x) {
    int ret = 0;
    while (x < N) {
        ret += T[x];
        x = x + (x & (x ^ (x - 1)));
    }
    return ret;
}

void up(int x) {
    while (x > 0) {
        T[x]++;
        x = x - (x & (x ^ (x - 1)));
    }
}

int main() {
    //freopen("in.in", "r", stdin);
    freopen("bphoto.in", "r", stdin);
    freopen("bphoto.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c.pb(a[i]);
    }
    sort(c.begin(), c.end());

    int cnt = 0;
    for (int i = 0; i < c.size(); i++) {
        if (M[c[i]] == 0) {
            M[c[i]] = ++cnt;
        }
    }

    for (int i = 1; i <= n; i++) {
        a[i] = M[a[i]];
        L[i] = get(a[i] + 1);
        up(a[i]);
    }

    memset(T, 0, sizeof(T));
    for (int i = n; i >= 1; i--) {
        R[i] = get(a[i] + 1);
        up(a[i]);
    }

    int dem = 0;
    for (int i = 1; i <= n; i++) {
        if (L[i] * 2 < R[i] || R[i] * 2 < L[i]) dem++;
    }

    cout << dem;
    /**/ return 0;
}
