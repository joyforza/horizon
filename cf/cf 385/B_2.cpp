#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 555
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, m;
string s;

int main() {

    freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> s;

        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'X') cnt++;
        }
    }

   // cout << cnt << "\n";

    if (cnt < m || cnt % m == 0) cout << "YES";
    else
        cout << "NO";

    /**/ return 0;
}
