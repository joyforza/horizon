#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, pp>
#define pp3 pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int nt;
int n, m;
bool f[222];
vector <int> a[222];
vector <vector<pp> > dat;
vector <pp> tmp;
int In[222];
int Out[222];

int par[222];
bool ed[222][222];
void dfs(int u) {

    f[u] = true;
    for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        if (f[v] == false) {
            tmp.pb(mp(u, v));
            ed[u][v] = true;
            ed[v][u] = true;
           // cout << "new edge: " << u << " " << v << "\n";
            In[v]++;
            Out[u]++;
            dfs(v);
        }
        else {
            if (ed[u][v] == false) {
                In[v]++;
                Out[u]++;
                ed[u][v] = true;
                ed[v][u] = true;
                tmp.pb(mp(u, v));
            }
        }
    }
}

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) a[i].clear();
        dat.clear();

        for (int i = 1; i <= m; i++) {
            int u, v;
            cin >> u >> v;
//            cout << "edge: " << u << " " << v << "\n"
            a[u].pb(v);
            a[v].pb(u);

        }

        //cout << "new: " << n << " " << m << "\n";

        int best = 1;
        int val = 0;

        for (int i = 1; i <= 1; i++) {
            memset(f, false, sizeof(f));
            tmp.clear();
            memset(In, 0, sizeof(In));
            memset(Out, 0, sizeof(Out));
            memset(ed, false, sizeof(ed));
            dfs(i);

            for (int j = 1; j <= n; j++)
                if (f[j] == false) dfs(j);


            dat.pb(tmp);


            int cnt = 0;
            for (int j = 1; j <= n; j++) cnt += (In[j] == Out[j]);
            if (cnt > val) {
                val = cnt;
                best = i;
            }
        }


        cout << val << "\n";
        for (int i = 0; i < dat[best - 1].size(); i++)
            cout << dat[best - 1][i].fi << " " << dat[best - 1][i].se << "\n";
    }
    /**/return 0;
}
