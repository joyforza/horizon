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
#define N 1005
#define base 311097
#define M (1 << 16) + 1
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

struct node {
    int en[27];
    int val[27];
};


int nt, n, h;
vector<int> a[N];
int t[N];
bool f[N];

node d[N]; // all
node com[(1 << 10) + 1];

void dfs(int u) {

    vector<int> tmp;

    f[u] = true;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            dfs(v);
            tmp.pb(v);
        }
    }


    int sz = tmp.size();

    // init 1
    for (int i = 1; i <= h; i++)
        if (i + t[u] <= h) {
            // use current day
            com[0].val[i] = 1;
            com[0].en[i] = i + t[u];
        }
        else {
            // use next day
            com[0].val[i] = 2;
            com[0].en[i] = t[u] + 1;
        }



    // init 2
    for (int i = 1; i < (1 << sz); i++)
        for (int st = 1; st <= h; st++)
            com[i].val[st] = inf;

    for (int i = 0; i < (1 << sz) - 1; i++)
    for (int st = 1; st <= h; st++) {

        for (int j = 0; j < sz; j++)
            if (((i >> j) & 1) == 0) {
                // bit on
                int nstt = (i | (1 << j));

                int v = tmp[j]; // get node

                // case 1
                int new_val = com[i].val[st] + d[v].val[com[i].en[st]] - 1;
                if (new_val < com[nstt].val[st]) {
                    com[nstt].val[st] = new_val;
                    com[nstt].en[st] = d[v].en[com[i].en[st]];
                }
            }
    }
    // update
    for (int i = 1; i <= h; i++) {
        d[u].val[i] = com[(1 << sz) - 1].val[i];
        d[u].en[i] = com[(1 << sz) - 1].en[i];
    }
 }

int main() {
    freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while(nt--) {
        cin >> n >> h;
        h++;
        for (int i = 1; i <= n; i++) a[i].clear();
        for (int i = 1; i <= n; i++) cin >> t[i];
        for (int i = 1; i <= n; i++) {
            int num, x;
            cin >> num;
            for (int j = 1; j <= num; j++) {
                cin >> x;
                a[i].pb(x);
            }
        }

        memset(f, false, sizeof(f));
        dfs(1);
        int ret = inf;
        // get min
        for (int i = 1; i <= h; i++)
            ret = min(ret, d[1].val[i]);
        // result
        cout << ret << "\n";
    }
    /**/ return 0;
}
