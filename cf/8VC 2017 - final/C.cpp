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
#define N 200010
#define base 311097
#define MAXN 505
#define MAXE 1000001
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
int n;
int p[N];
bool vs[N];
int b[N];

int main() {
    //freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);

    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) cin >> p[i];
    for (int i = 1; i <= n; i++)
    if (vs[i] == false) {
        cnt++;
        int st = i;
        while (!vs[st]) {
            vs[st] = true;
            st = p[st];
        }
    }

    if (cnt == 1) cnt = 0;

    int d = 0;
    for (int i = 1; i <= n; i++) {
         cin >> b[i];
         d += (b[i] == 1);
    }

    cnt += (d % 2 == 0);

    cout << cnt;
    /**/ return 0;
}
