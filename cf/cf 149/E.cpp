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
#define N 100010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

int T[22][4 * N];
int add[22][4 * N];
int a[N];
int n, m;


void modify(int id, int node, int l, int r, int u, int v) {
    if (r < u || l > v) return;

    if (l >= u && r <= v) {
        add[id][node]++;
        return;
    }

    int mid = (l + r) >> 1;

    // Lazy
    add[id][node * 2] += add[id][node];
    add[id][node * 2 + 1] += add[id][node];
    add[id][node] = 0;

    modify(id, node * 2, l, mid, u, v);
    modify(id, node * 2 + 1, mid + 1, r, u, v);

    // update parent
    T[id][node] = 0;
    T[id][node] += (add[id][node * 2] % 2 != 0 ? (mid - l + 1) - T[id][node * 2]: T[id][node * 2]);
    T[id][node] += (add[id][node * 2 + 1] % 2 != 0 ? (r - mid) - T[id][node * 2 + 1]: T[id][node * 2 + 1]);
}

int get(int id, int node, int l, int r, int u, int v) {
    if (r < u || l > v) return 0;
    if (l >= u && r <= v) {
        if (add[id][node] % 2 != 0) return (r - l + 1) - T[id][node];
        else
            return T[id][node];
    }
    int ret = 0;
    int mid = (l + r) >> 1;

    // LAZY
    add[id][node * 2] += add[id][node];
    add[id][node * 2 + 1] += add[id][node];
    add[id][node] = 0;

    ret += get(id, node * 2, l, mid, u, v);
    ret += get(id, node * 2 + 1, mid + 1, r, u, v);

    // update parent
    T[id][node] = 0;
    T[id][node] += (add[id][node * 2] % 2 != 0 ? (mid - l + 1) - T[id][node * 2]: T[id][node * 2]);
    T[id][node] += (add[id][node * 2 + 1] % 2 != 0 ? (r - mid) - T[id][node * 2 + 1]: T[id][node * 2 + 1]);
    return ret;
}

void init(int id, int node, int l, int r) {
    if (l == r) {
        T[id][node] = ((a[l] >> id) & 1);
        return;
    }

    int mid = (l + r) >> 1;

    init(id, node * 2, l, mid);
    init(id, node * 2 + 1, mid + 1, r);

    T[id][node] += T[id][node * 2];
    T[id][node] += T[id][node * 2 + 1];
}



int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 0; i <= 20; i++)
        init(i, 1, 1, n);


    cin >> m;
    for (int i = 1; i <= m; i++) {
        int tp, l, r, x;
        cin >> tp >> l >> r;
        if (tp == 1) {
            long long ret = 0;
            for (int j = 0; j <= 20; j++) {
                ret += (ll)get(j, 1, 1, n, l, r) * (1 << j);
            }
            cout << ret << "\n";
        }
        else {
            cin >> x;
            for (int j = 0; j <= 20; j++)
                if ((x >> j) & 1) {
                    modify(j, 1, 1, n, l, r);
                }
        }
    }
    /**/ return 0;
}
