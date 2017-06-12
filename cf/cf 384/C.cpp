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
#define N 100010
#define base 311097
#define M 10000001
typedef long long ll;
typedef long double ld;
using namespace std;
int n;

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    cin >> n;
    if (n == 1) cout << -1;
    else
        cout << n << " " << n + 1 << " " << n * (n + 1);
    /**/ return 0;
}
