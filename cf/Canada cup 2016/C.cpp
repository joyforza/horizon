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
#define N 10010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
string s;
bool a[55][55];

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        int u = s[i] - 'a' + 1;
        int v = s[i + 1] - 'a' + 1;
        a[u][v] = true;
        a[v][u] = true;
    }


    vector <int> d1;
    vector <int> d2;
    int d3 = 0;
    vector <int> d;
    int node = 0;

    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (i != j && a[i][j]) cnt++;

        if (cnt == 0) continue;
        node++;
        if (cnt == 3) d1.pb(i);
        else
        if (cnt == 5) d2.pb(i);
        else
            d3++;
        d.pb(i);
    }
    if (node % 2 != 0)
        cout << "Impossible";
    else
    if (node == 2) {
        cout << d[0] << "\n";
        cout << d[1] << "\n";
    }
    else {
        if (node )
    }
    /**/ return 0;
}
