#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 200010
#define mod 1000000007
typedef long long ll;
using namespace std;
int n, c, d;

vector<int> C[N];
vector<int> D[N];
vector<pp> a;
vector<pp> b;

bool cmp(pp x, pp y) {
    if (x.fi != y.fi) return x.fi < y.fi;
    return x.se < y.se;
}

bool f[N];

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> n >> c >> d;
    for (int i = 1; i <= n; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        if (c == 'C') {
            C[u].pb(v);
        }
        else {
            D[u].pb(v);
        }
    }

    int ret = 0;

    int bestC = 0;
    int bestD = 0;

    for (int i = 1; i <= 100000; i++)
    if (C[i].size() > 0) {

        if (C[i].size() > 1) {
            vector<int> tmp;
            for (int j = 0; j < C[i].size(); j++) tmp.pb(C[i][j]);
            sort(tmp.begin(), tmp.end());
            if (tmp[0] + tmp[1] <= c) ret = max(ret, i + i);
            a.pb(mp(tmp[0], i));
            if (tmp[0] <= c) bestC = i;
        }
        else {
            a.pb(mp(C[i][0], i));
            if (C[i][0] <= c) bestC = i;
        }
    }

    for (int i = 1; i <= 100000; i++)
    if (D[i].size() > 0) {
        if (D[i].size() > 1) {
            vector<int> tmp;
            for (int j = 0; j < D[i].size(); j++) tmp.pb(D[i][j]);
            sort(tmp.begin(), tmp.end());
            if (tmp[0] + tmp[1] <= d) ret = max(ret, i + i);
            b.pb(mp(tmp[0], i));
            if (tmp[0] <= d) bestD = i;
        }
        else {
            b.pb(mp(D[i][0], i));
            if (D[i][0] <= d) bestD = i;
        }
    }

   // cout << bestC << " " << bestD << "\n";

    if (bestC > 0 && bestD > 0)
        ret = max(ret, bestC + bestD);


    sort(a.begin(), a.end(), cmp);
    sort(b.begin(), b.end(), cmp);

    memset(f, false, sizeof(f));
    priority_queue<pp> qu;
    for (int i = 0; i < a.size(); i++) {
        qu.push(mp(a[i].se, a[i].fi));

    }

    for (int i = 0; i < a.size(); i++) {

        if (a[i].fi > c) break;

        f[a[i].fi] = true;

        int need = c - a[i].fi;

        while (!qu.empty() && (f[qu.top().se] || qu.top().se > need)) qu.pop();

                if (qu.empty()) break;


        ret = max(ret, a[i].se + qu.top().fi);
    }


    while (!qu.empty()) qu.pop();
    memset(f, false, sizeof(f));

    for (int i = 0; i < b.size(); i++) {
        qu.push(mp(b[i].se, b[i].fi));
    //    cout << "this = " << b[i].se << " " << b[i].fi << "\n";
    }

   // cout << "d = " << d << "\n";

    for (int i = 0; i < b.size(); i++) {
        if (b[i].fi > d) break;

        f[b[i].fi] = true;

        int need = d - b[i].fi;

        while (!qu.empty() && (f[qu.top().se] || qu.top().se > need)) qu.pop();

        if (qu.empty()) break;

     //   cout << "ok @@";
        ret = max(ret, b[i].se + qu.top().fi);
    }

    cout << ret;
    /**/return 0;
}
