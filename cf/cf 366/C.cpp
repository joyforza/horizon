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
#define N 300010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, q;
int t, u;
int st[N];
int m = 0;
vector <int> ps[N];
bool dd[N];

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> q;
    int cnt = 0;
    for (int i = 1; i <= q; i++) {
        cin >> t >> u;
        if (t == 1) {
            st[++m] = u;
            cnt++;
            ps[u].pb(m);
        }
        else
        if (t == 2) {
            for (int j = 0; j < ps[u].size(); j++)
            if (dd[ps[u][j]] == false)
            {
                dd[ps[u][j]] = true;
                cnt--;
            }
            ps[u].clear();
        }
        else {

            while (u > 0) {
                int rr = st[m];
                if (dd[rr] == false) {
                    u--;
                    cnt--;
                }
                if (ps[rr].size() > 0) {
                  if (ps[rr][ps[rr].size() - 1] == m)  ps[rr].pop_back();
                }
                m--;
            }
        }
        cout << cnt << endl;
    }
    /**/ return 0;
}
