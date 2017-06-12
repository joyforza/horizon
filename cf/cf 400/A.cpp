#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 100005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

string a, b;
int n;

int main() {
   // freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> a >> b;



    cin >> n;
    cout << a << " " << b << "\n";

    for (int i = 1; i <= n; i++) {
        string u, v;
        cin >> u >> v;
        if (u == a) {
            a = v;
        }
        else
        if (v == a) {
            a = u;
        }
        else
        if (u == b) {
            b = v;
        }
        else {
            b = u;
        }
        cout << a << " " << b << "\n";
    }

    /**/ return 0;
}

