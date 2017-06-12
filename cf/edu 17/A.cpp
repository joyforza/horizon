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
ll n;
int k;
vector <ll> ret;

int main() {
    //freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (ll i = 1; i <= sqrt(n); i++)
    if (n % i == 0) {
        ret.pb(i);
        if (n / i != i)
            ret.pb(n / i);
    }
    sort(ret.begin(), ret.end());
    if (k > ret.size()) cout << -1;
    else
        cout << ret[k - 1];
    /**/ return 0;
}
