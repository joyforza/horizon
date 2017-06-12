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
#define N 500005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
vector <string> s;
int len[N];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        s.pb(x);
        len[i] = x.size();
    }

    for (int i = n - 2; i >= 0; i--) {
        bool ok = false;
        for (int j = 0; j < min(len[i], len[i + 1]); j++)
        if (s[i][j] > s[i + 1][j]) {
            len[i] = j;
            ok = true;
            break;
        }
        else
        if (s[i][j] < s[i + 1][j]) {
            ok = true;
            break;
        }
        if (ok) continue;
        if (len[i] > len[i + 1]) {
            len[i] = len[i + 1];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < len[i]; j++)
            cout << s[i][j];
        cout << "\n";
    }

    /**/ return 0;
}

