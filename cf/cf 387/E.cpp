#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 1000010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
string s;
vector <vector<char> > a;
int par[N];
int id[N];
int cnt = 0;
int sz[N];
int need[N];
int dep[N];
vector <char> name[N];
int curPar = -1;
vector <int> ds[N];

int getInt(vector <char> x) {
    int val = 0;
    for (int i = 0; i < x.size(); i++)
        val = val * 10 + (x[i] - '0');
    return val;
}

void up(int node) {
    if (node == -1) return;
    if (need[node] == sz[node]) {
        curPar = par[node];
        up(par[node]);
    }
}

void out(vector <char> x) {
    for (int i = 0; i < x.size(); i++)
        cout << x[i];
    cout << " ";
}

int main() {

    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;
    s = s + ',';
    vector <char> tmp;
    memset(par, -1, sizeof(par));
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ',') {
            a.pb(tmp);
            tmp.clear();
        }
        else {
            tmp.pb(s[i]);
        }
    }

    for (int i = 0; i < a.size(); i += 2) {
        cnt++;
        /// name
        name[cnt] = a[i];
        need[cnt] = getInt(a[i + 1]);
        if (curPar != -1) {
            dep[cnt] = dep[curPar] + 1;
            sz[curPar]++;
        }
        /// change root
        par[cnt] = curPar;
        curPar = cnt;
        if (need[cnt] == 0) {
            up(cnt);
        }
    }

    int ret = 0;
    for (int i = 1; i <= cnt; i++) {
        ret = max(ret, dep[i] + 1);
        ds[dep[i] + 1].pb(i);
    }

    cout << ret << "\n";
    for (int i = 1; i <= ret; i++) {
        for (int j = 0; j < ds[i].size(); j++)
            out(name[ds[i][j]]);
        cout << "\n";
    }
    /**/ return 0;
}
