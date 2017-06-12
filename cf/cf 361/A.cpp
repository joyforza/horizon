#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 10010
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int dx[] = {4, 1, 1, 1, 2, 2, 2, 3, 3, 3};
int dy[] = {2, 1, 2, 3, 1, 2, 3, 1, 2, 3};
int p[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
vector <int> px;
vector <int> py;
string s;

bool check(int x, int y) {
    if (x < 1 || x > 4 || y < 1 || y >= 4) return false;
    if (x == 4 && y == 1) return false;
    if (x == 4 && y == 3) return false;
    return true;
}

bool valid(int u, int v) {
    for (int i = 0; i < px.size(); i++) {
        u = u + px[i];
        v = v + py[i];
        if (!check(u, v)) return false;
    }
    return true;
}

int main() {
//    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size() - 1; i++) {
        int d2 = s[i + 1] - '0';
        int d1 = s[i] - '0';
        px.pb(dx[d2] - dx[d1]);
        py.pb(dy[d2] - dy[d1]);
     //   cout << px[i] << " " << py[i] << "\n";
    }
    bool ok = false;
    int cut = s[0] - '0';
    for (int i = 0; i <= 9; i++)
    if (i != cut) {
        ok |= valid(dx[i], dy[i]);

          }

   // cout << check(1, 4);
    puts(ok ? "NO" : "YES");
   /**/ return 0;
}
