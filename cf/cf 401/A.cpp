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

int n;

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    n = n % 6;

    int a[] = {0, 1, 2};

    for (int i = 1; i <= n; i++) {

        if (i % 2 != 0) {
                swap(a[0], a[1]);

        }
        else
            swap(a[1], a[2]);

    }

   // cout << a[0] << " " << a[1] << " " << a[2] << "\n";

    int x;
    cin >> x;
    cout << a[x];
    /**/ return 0;
}

