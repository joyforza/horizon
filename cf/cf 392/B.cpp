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
#define N 123
#define base 311097
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
string s;
int a[N];
int d[5];

bool check(int x, int y, int u, int v) {
    if (x == y || x == u || x == v) return false;
    if (y == u || y == v) return false;
    if (u == v) return false;

    memset(d, 0, sizeof(d));

    int n = s.size();

    for (int i = 0; i < n; i += 4) {
        if (i < n) {
            if (a[i] == -1) {
                d[x]++;
            }
            else
            if (a[i] != x) return false;
        }
        if (i + 1 < n) {
            if (a[i + 1] == -1) {
                d[y]++;
            }
            else
            if (a[i + 1] != y) return false;
        }

        if (i + 2 < n) {
            if (a[i + 2] == -1) {
                d[u]++;

            }
            else
            if (a[i + 2] != u) return false;
        }

        if (i + 3 < n) {
            if (a[i + 3] == -1) {
                d[v]++;


            }
            else
            if (a[i + 3] != v) return false;
        }
    }
    return true;
}

int main() {
    //freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '!') a[i] = -1;
        else
            if (s[i] == 'R') a[i] = 0;
        else
            if (s[i] == 'B') a[i] = 1;
        else
            if (s[i] == 'Y') a[i] = 2;
        else
            a[i] = 3;
    }

   // check(2, 3, 0, 1);

    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            for (int k = 0; k < 4; k++)
                for (int h = 0; h < 4; h++)
                    if (check(i, j, k, h)) {
                       // cout << i << " " << j << " " << k << " " << h << "\n";
                        cout << d[0] << " " << d[1] << " " << d[2] << " " << d[3];
                        return 0;
                    }
    /**/ return 0;
}
