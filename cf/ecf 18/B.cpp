#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, k;
bool f[N];
vector<int> rm;

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;

    for (int i = 1; i <= n; i++) rm.pb(i);

    for (int i = 1; i <= k; i++) {
        int x;
        cin >> x;
        int pos = x  % (int)rm.size();
        cout << rm[pos] << " ";
        f[rm[pos]] = true;
        pos++;
        if (pos == rm.size()) pos = 0;
        int val = rm[pos];
        rm.clear();
        for (int j = val; j <= n; j++) if (f[j] == false) rm.pb(j);
        for (int j = 1; j < val; j++) if (f[j] == false) rm.pb(j);

    }

    /**/ return 0;
}
