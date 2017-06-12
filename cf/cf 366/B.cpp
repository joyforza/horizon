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
int n, x;
int cnt;

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        cnt += (x - 1);
        if (cnt % 2 == 0)
            cout << 2 << endl;
        else
            cout << 1 << endl;
    }
   /**/ return 0;
}
