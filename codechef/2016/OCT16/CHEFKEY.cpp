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
int m, n, c;

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        int ret = 0;
        cin >> n >> m >> c;
        for (int i = 1; i <= c; i++)
        if (c % i == 0) {
            int d = c / i;
            if (i <= n && d <= m) ret++;
        }
        cout << ret << "\n";
    }

   /**/return 0;
}
