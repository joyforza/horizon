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
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m, q;
string a;
int lab[N];
map<string, int> M;
map<pp, int> H;

int get(int u) {
    if (lab[u] < 0) return u;
    lab[u] = get(lab[u]);
    return lab[u];
}

void uni(int r1, int r2) {
    int x = lab[r1] + lab[r2];
    if (lab[r1] < lab[r2]) {
        lab[r2] = r1;
        lab[r1] = x;
    }
    else {
        lab[r2] = x;
        lab[r1] = r2;
    }
}

bool checkOp(int r1, int r2) {
    if (!H.count(mp(r1, r2))) return false;
    return true;
}

int main() {
    freopen("in.in", "r", stdin);
    freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(lab, -1, sizeof(lab));

    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
            cin >> a;
            M[a] = i;
    }

    for (int i = 1; i <= m; i++) {
        int t;
        string u, v;
        cin >> t >> u >> v;
        int idu = M[u];
        int idv = M[v];

        cout << "two id = " << idu << " " << idv << "\n";
        int r1 = get(idu);
        int r2 = get(idv);

        cout << "two root: " << r1 << " " << r2 << "\n";

        if (t == 1) {

        cout << "same mean\n";

            if (checkOp(r1, r2)) cout << "NO\n";
            else {
                if (r1 != r2)
                uni(r1, r2);
                cout << "YES\n";
            }
        }
        else {

        cout << "hate\n";

            if (r1 == r2) cout << "NO\n";
            else {
                H[mp(r1, r2)] = 1;
                H[mp(r2, r1)] = 1;
                cout << "YES\n";
            }
        }/**/
    }

    for (int i = 1; i <= q; i++) {
        string u, v;
        cin >> u >> v;
        int idu = M[u];
        int idv = M[v];
        ///
        int r1 = get(idu);
        int r2 = get(idv);
        if (r1 == r2) cout << 1 << "\n";
        else
            if (checkOp(r1, r2)) cout << 2 << "\n";
        else
            cout << 3 << "\n";
    }
    /**/ return 0;
}
