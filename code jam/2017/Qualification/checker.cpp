#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;


int main() {
    //freopen("B_2.in", "r", stdin);
    freopen("B_3.in", "w", stdout);
    ios::sync_with_stdio(false);
    int n = 1000;
    cout << n << "\n";
    for (int i = 1; i <= n; i++) {
        cout << rand() % 9 + 1;
        for (int j = 1; j <= 5; j++)
            cout << rand() % 10;
        cout << "\n";
    }
    /**/ return 0;
}
