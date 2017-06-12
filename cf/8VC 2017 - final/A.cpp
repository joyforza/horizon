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
#define MAXE 1000001
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;

int numDay(int x) {
    if (x == 1 || x == 3 || x == 5) return 31;
    if (x == 7 || x == 8 || x == 10 || x == 12) return 31;
    if (x == 2) return 28;
    return 30;
}

int n, m;

int main() {
    //freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> m >> n;

    int sn = numDay(m);

    n = 8 - n;
    sn -= n;
    int ret = 1;
    ret += (sn/ 7) + (sn % 7 != 0);

    cout << ret;
    return 0;
}
