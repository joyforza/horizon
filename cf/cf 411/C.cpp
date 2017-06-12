#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 300010
#define mod 1000000007
typedef long long ll;
using namespace std;
int n, m;
vector <int> ds[N];
vector <int> a[N];
int c[N];
bool f[N];
map<int, bool> M;

bool cmp2(int x, int y) {
    return (int)a[x].size() > (int)a[y].size();
}

void goColor(int u) { /// color set u
    f[u] = true;
    M.clear();
    int cur = 1;
    for (int i = 0; i < ds[u].size(); i++) {
        int v = ds[u][i];
        if (c[v] != -1) M[c[v]] = true;
    }

    vector<int> tmp;
    for (int i = 0; i < ds[u].size(); i++) {
        int v = ds[u][i];
        if (c[v] == -1) {
            while (M.count(cur)) cur++;
            c[v] = cur;
            M[cur] = true;
            tmp.pb(v);
        }
    }
    //sort(tmp.begin(), tmp.end(), cmp2);
    for (int i = 0; i < tmp.size(); i++) {
        int v = tmp[i];
        for (int j = 0; j < a[v].size(); j++) {
            int id = a[v][j];
            if (f[id] == false) {
                goColor(id);
            }
        }
    }
}

int rr[N];
int val[N];

bool cmp(int x, int y) {

     int sz1 = ds[x].size();
    int sz2 = ds[y].size();
    if (sz1 != sz2) {
        return (sz1 > sz2);
    }
    return (val[x] > val[y]);
}

int main() {
	freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(c, -1, sizeof(c));
    //cin >> n >> m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i<= n; i++) {
        int k;
        //cin >> k;
        scanf("%d", &k);
        for (int j = 1; j <= k; j++) {
            int x;
            //cin >> x;
            scanf("%d", &x);
            a[x].pb(j);
            ds[i].pb(x);
        }
    }

    for (int i = 1; i <= n; i++) {
        val[i] = 0;
        for (int j = 0; j < ds[i].size(); j++) {
            int u = ds[i][j];
            val[i] += (int)a[u].size();
        }
    }

    for (int i = 1; i <= m; i++) rr[i] = i;
    sort(rr + 1, rr  + m + 1, cmp2);

    for (int i = 1; i <= m; i++) {
       // int node = rr[i];

        for (int j = 0; j < a[i].size(); j++) {
            int u = a[i][j];
            if (f[u] == false) {
                goColor(u);
                cout << "go = " << u << "\n";
            }
        }
    }


    int ret = 0;
    for (int i = 1; i <= m; i++) ret = max(ret, c[i]);
    //cout << ret << "\n";
    printf("%d\n", ret);
    for (int i = 1; i <= m; i++)
        //cout << c[i] << " ";
        printf("%d ", c[i]);

	return 0;
}
