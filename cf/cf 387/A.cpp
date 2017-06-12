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
int n;

int main() {

    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    int best = inf;
    int u, v;
    cin >> n;
    for (int i = 1; i <= n; i++)
    if (n % i == 0) {
        int a = i;
        int b = n / i;
        if (a <= b && b - a < best) {
            best = b - a;
            u = a;
            v = b;
        }
    }

    cout << u << " " << v;
    /**/ return 0;
}
