#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, ll>
#define ppp pair<pp, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 30
#define base 311097
#define maxN 100011
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
vector <int> ret;

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    if (n % 2 != 0) {
        ret.pb(3);
        n -= 3;
    }
    for (int i = 1; i <= n / 2; i++)
        ret.pb(2);
    cout << ret.size() << "\n";
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << " ";
    /**/ return 0;
}
