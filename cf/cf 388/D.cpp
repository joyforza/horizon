#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, ll>
#define ppp pair<pp, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
#define maxN 100011
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
priority_queue <pp> qu;
priority_queue <pp> qu2;

int best[N];
bool f[N];
bool dd[N];
int a[N];
int m;
vector <pp> del;
vector <int> delMax;
vector <int> b[N];

int cc(int id, int val) {
    //cout << val << "\n";

    if (b[id].size() == 0) return -1;
    int l = 0;
    int r = (int)b[id].size() - 1;
    int ret = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (b[id][mid] > val) {
            ret = b[id][mid];
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ret;
}

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        qu.push(mp(v, u));
        best[u] = max(best[u], v);
        b[u].pb(v);
    }

    for (int i = 1; i <= n; i++)
    if (best[i] > 0) {
        qu2.push(mp(best[i], i));
    }

    int q;
    scanf("%d", &q);

    while (q--) {

        scanf("%d", &m);

        del.clear();
        delMax.clear();

        for (int i = 1; i <= m; i++) {
            scanf("%d", &a[i]);
            f[a[i]] = true;
            dd[a[i]] = true;
        }


        while (true) {

            if (qu.empty()) {
                printf("0 0\n");
                break;
            }

            int id = qu.top().se;
            int val = qu.top().fi;

            if (f[id] == false) {
              //  printf("%d %d\n", id, val);
                dd[id] = true;

                int zone = -1;

                //printf("we get id = %d\n", id);

                 while (true) {
                    if (qu2.empty()) break;

                    //printf("%d\n", qu2.size());

                    int id = qu2.top().se;
                    int val = qu2.top().fi;

                    //printf("%d %d %d\n", id, val, dd[id]);

                    if (dd[id] == false) {
                        zone = val;
                        break;
                    }
                    else {
                        delMax.pb(id);
                        qu2.pop();
                    }
                }


                dd[id] = false;

                if (zone == -1) {
                    val = b[id][0];
                }
                else {
                    val = cc(id, zone);
                }


                printf("%d %d\n", id, val);
                break;
            }
            else {
                del.pb(mp(val, id));
                qu.pop();
            }
        }
        /**/

        /// return
        for (int i = 0; i < (int)del.size(); i++)
            qu.push(mp(del[i].fi, del[i].se));

        for (int i = 0; i < (int)delMax.size(); i++)
            qu2.push(mp(best[delMax[i]], delMax[i]));

        for (int i = 1; i <= m; i++) {
            f[a[i]] = false;
            dd[a[i]] = false;
        }
    }

    /**/ return 0;
}
