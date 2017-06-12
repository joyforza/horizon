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
int tr[MaxE];
vector <int> dup;
int tr2[MaxE];
int tr3[MaxE];
/// meet in middle
/*
void split(int x) {
    int d1 = tr2[x];
    int d2 = x - d1;
    int p1 = sqrt(tr[d1]);
    int p2 = sqrt(d1 - tr[d1]);
    int p3 = sqrt(tr[d2]);
    int p4 = sqrt(d2 - tr[d2]);
    printf("%d %d %d %d\n", p1, p2, p3, p4);
}
*/

int n, m, P;
ll T[4 * N];
int a[N];

ll mul(ll x, ll y) {

}

void up(int node, int l, int r, int x, int val) {
    if (l > x || r < x) return;
    if (l == r) {
        T[node] = val % P;
        return;
    }
    int mid = (l + r) >> 1;
    up(node * 2, l, mid, x, val);
    up(node * 2 + 1, mid + 1, r, x, val);
    T[node] = mul(T[node * 2], T[node * 2 + 1]);
}

ll get(int node, int l, int r, int u, int v) {
    if (l > v || r < u) return 1;
    if (l >= u && r <= v) {
        return T[node];
    }
    int mid = (l + r) >> 1;
    ll ret = 1;
    ret = mul(ret, get(node * 2, l, mid, u, v));
    ret = mul(ret, get(node * 2 + 1, mid + 1, r, u, v));
    return ret;
}

void init(int node, int l, int r) {
    if (l == r) {
        T[node] = a[l] % P;
        return;
    }
    int mid = (l + r) >> 1;
    init(node * 2, l, mid);
    init(node * 2 + 1, mid + 1, r);
    T[node] = mul(T[node * 2], T[node * 2 + 1]);
}

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(tr, -1, sizeof(tr));
    for (int i = 0; i < MaxE; i++) {
        int d = sqrt(i);
        if (d * d == i) {
            int lim = sqrt(MaxE - i);
            for (int j = 1; j <= lim; j++)
                tr[i + j * j] = i;
        }
    }

    tr[0] = 0;

    for (int i = 1; i < MaxE; i++) {
            for (int j = 0; j <= sqrt(i); j++)
                if (tr[i - j * j] != -1) {
                    tr2[i] = i - j * j;
                    break;
                }
        }

    int dem = 0;
    for (int i = 0; i < MaxE; i++)
        if (tr2[i] != -1) dem++;

    cout << dem;
 // split(1000000);
  //  for (int i = 0; i <= 1000000; i++)
  //      split(i);

    int nt;
    scanf("%d", &nt);
    while(nt--) {
        scanf("%d%d%d", &n, &m, &P);

        for (int i = 1; i <= n; i++)
            scanf("%d", a + i);

        init(1, 1, n);

        for (int i = 1; i <= m; i++) {
            int tp, u, v;
            scanf("%d%d%d", &tp, &u, &v);
            if (tp == 2) {
                int ret = get(1, 1, n, u, v);
                //printf("%d\n", ret);
               // split(ret);
            }
            else {
                up(1, 1, n, u, v);
            }
        }
    }
    /**/ return 0;
}
