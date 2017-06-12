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
#define N 30010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
string s[2];
int n;

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    s[0] = "I hate";
    s[1] = "I love";
    for (int i = 0; i < n; i++) {
        cout << s[i % 2];
        if (i < n - 1) cout << " that ";
    }
    cout << " it";

   /**/ return 0;
}
