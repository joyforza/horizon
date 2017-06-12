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
#define N 50005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
string s;

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;

    int ok = -1;

    for (int i = 0; i < s.size(); i++) {
        int c = s[i] - 'a';
        if (c - ok > 1) {
            cout << "NO";
            return 0;
        }
        if (c > ok) ok++;
    }
    cout << "YES";
    /**/ return 0;
}

