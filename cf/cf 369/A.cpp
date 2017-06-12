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
#define N 256
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
string s[1010];

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        if (ok) continue;
        if (s[i][0] == 'O' && s[i][1] == 'O') {
            s[i][0] = '+';
            s[i][1] = '+';
            ok = true;
            continue;
        }
        if (s[i][3] == 'O' && s[i][4] == 'O') {
            s[i][3] = '+';
            s[i][4] = '+';
            ok = true;

        }
    }
    if (!ok) cout << "NO";
    else{
        cout << "YES\n";
        for (int i = 1; i <= n; i++)
            cout << s[i] << "\n";
    }
    /**/ return 0;
}
