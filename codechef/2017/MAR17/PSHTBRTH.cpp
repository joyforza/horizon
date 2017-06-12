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
int nt;
int n, m;
vector<int> a[M + 1];
int dp[M + 1];
bool f[M + 1];

int grundy(vector<int> mv) {
    set<int> s;
    for (int i = 0; i < mv.size(); i++) s.insert(mv[i]);
    int ret = 0;
    while (s.count(ret)) ret++;
    return ret;
}

int compute(int n) {
    if (f[n]) return dp[n];
    f[n] = true;
    vector<int> tmp;
    for (int i = 0; i < a[n].size(); i++) {
        tmp.pb(compute(a[n][i]));
    }

    dp[n] = grundy(tmp);
    tmp.clear();

    return dp[n];
}


int tmp[11][11];
int sum[11][11];
int one[11][11];
int c[N];
int T[4 * N]; // interval tree

int getRect(int r1, int c1, int r2, int c2) {
    return sum[r2][c2] - sum[r1 - 1][c2] - sum[r2][c1 - 1] + sum[r1 - 1][c1 - 1];
}

// all candle in rect
bool check(int r1, int c1, int r2, int c2) {
    int d = one[r2][c2] - one[r1 - 1][c2] - one[r2][c1 - 1] + one[r1 - 1][c1 - 1];
    return (d == (r2 - r1 + 1) * (c2 - c1 + 1));
}

string s;

int getNext() {
    int val = 0;
    for (int i = 0; i < 4; i++) {
        cin >> s;
        for (int j = 0; j < 4; j++) {
            if (s[j] == '1') {
                val |= (1 << (i * 4 + j));
            }
        }
    }
    return val;
}

void initTree(int node, int l, int r) {
    if (l == r) {
        T[node] = dp[c[l]];
        return;
    }
    int mid = (l + r) >> 1;
    initTree(node * 2, l, mid);
    initTree(node * 2 + 1, mid + 1, r);
    T[node] = T[node * 2] ^ T[node * 2 + 1];
}

int get(int node, int l, int r, int u, int v) {
    int ret = 0;
    if (u > r || v < l) return 0;
    if (l >= u && r <= v) {
        return T[node];
    }
    int mid = (l + r) >> 1;
    ret ^= get(node * 2, l, mid, u, v);
    ret ^= get(node * 2 + 1, mid + 1, r, u, v);
    return ret;
}

void update(int node, int l, int r, int pos, int val) {
    if (pos < l || pos > r) return;
    if (l == r) {
        T[node] = val;
        return;
    }
    int mid = (l + r) >> 1;
    update(node * 2, l, mid, pos, val);
    update(node * 2 + 1, mid + 1, r, pos, val);
    T[node] = T[node * 2] ^ T[node * 2 + 1];
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);

    for (int i = 1; i < (1 << 16); i++) {
        // init
        memset(tmp, 0, sizeof(tmp));
        memset(sum, 0, sizeof(sum));
        memset(one, 0, sizeof(one));

        for (int j = 0; j < 16; j++) {
            if ((i >> j) & 1) {
                int r = j / 4;
                int c = j % 4;
                tmp[r][c] = 1;
              //  cout << r << ", " << c << "\n";
            }
        }

        for (int u = 1; u <= 4; u++)
            for (int v = 1; v <= 4; v++) {
                int add = tmp[u - 1][v - 1] * (1 << (4 * (u - 1) + v - 1));
                sum[u][v] = sum[u - 1][v] + sum[u][v - 1] - sum[u - 1][v - 1] + add;
                one[u][v] = one[u - 1][v] + one[u][v - 1] - one[u - 1][v - 1] + tmp[u - 1][v - 1];
            }


        // find all sub ==> wrong
        for (int r1 = 1; r1 <= 4; r1++)
            for (int c1 = 1; c1 <= 4; c1++)
                for (int r2 = r1; r2 <= 4; r2++)
                    for (int c2 = c1; c2 <= 4; c2++) {
                            int add = getRect(r1, c1, r2, c2);
                            if (check(r1, c1, r2, c2))
                                a[i].pb(sum[4][4] - add);
                        }
    }

    // pre-compute
    f[0] = true;
    for (int i = (1 << 16) - 1; i > 0; i--)
        if (f[i] == false)
            dp[i] = compute(i);


    cin >> nt;
    while(nt--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            c[i] = getNext();
        }

        initTree(1, 1, n);

        for (int i = 1; i <= m; i++) {
            int tp;
            cin >> tp;
            if (tp == 1) {
                int l, r;
                cin >> l >> r;
                int val = get(1, 1, n, l, r);

               // cout << val << "\n";

                if (val)
                    cout << "Pishty\n";
                else
                    cout << "Lotsy\n";
            }
            else {
                int pos, val;
                cin >> pos;
                val = getNext();
                update(1, 1, n, pos, dp[val]);
            }
        }
    }

//    cout << a[1].size() << " " << dp[1] << "\n";

    /**/ return 0;
}
