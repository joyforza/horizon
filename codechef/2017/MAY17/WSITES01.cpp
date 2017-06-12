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
int n;
bool mark[N];
string s;
char c;
int nxt[N][30];
int node;
int par[N];
int cnt[N];
vector<int> tmp;
int label[N];

void add(int sign) {
    int cur = 0;
    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (nxt[cur][c] == -1) {
            node++;
            nxt[cur][c] = node;
            par[node] = cur;
            label[node] = c;
        }
        cur = nxt[cur][c];
        if (sign == 1) mark[cur] = true;
    }

    if (sign == 2) {
        tmp.pb(cur);
    }
}

void dfs(int u) {
    if (mark[u] == false) {
        tmp.pb(u);
        return;
    }
    for (int i = 0; i < 26; i++) {
        int v = nxt[u][i];
        if (v != -1)
            dfs(v);
    }
}

void findpath(int u) {

    vector<int> ans;

    ans.pb(label[u]);

    int v = u;
    while (v > 0) {
        v = par[v];
        if (v == 0) break;
        ans.pb(label[v]);
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << char('a' + ans[i]);
    cout << "\n";
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    memset(nxt, -1, sizeof(nxt));
    mark[0] = true;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> c >> s;
        if (c == '+') add(1);
        else
            add(2);
    }


    for (int i = 0; i < tmp.size(); i++)
        if (mark[tmp[i]]) {
            cout << -1;
            return 0;
        }


    tmp.clear();
    dfs(0);
    cout << tmp.size() << "\n";
    for (int i = 0; i < tmp.size(); i++) {
        findpath(tmp[i]);

    }
    return 0;
}
