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
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
string a;
string b;

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> a;
    cin >> b;

    if ((int)a.size() == (int)b.size()) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++)
            if (a[i] != b[i]) cnt++;
        if (cnt == 0) {
            cout << -1;
            return 0;
        }
    }

    cout << max((int) a.size(), (int) b.size());
    /**/ return 0;
}
