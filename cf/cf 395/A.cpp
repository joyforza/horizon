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
#define N 100010
#define base 311097
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL doubl e
#define EPS 1e-9
#define ll long long
using namespace std;
int n, m, z;
int f[10010];

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int ret =0;
    cin >> n >> m >> z;
    for (int i = n; i <= z; i+=n) f[i] = true;
    for (int i = m; i <= z; i+=m) if (f[i]) ret++;
    cout << ret;
    /**/ return 0;
}
