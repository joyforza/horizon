#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 10
#define N 100010
#define base 311097
#define M 10000001
typedef long long ll;
typedef long double ld;
using namespace std;

int pw(int a, int b) {
    int ret = 1;
    while (b > 0) {
        if (b & 1) {
            b--;
            ret = (ll)ret * a % mod;
        }
        else {
            a = (ll)a * a % mod;
            b /= 2;
        }
    }
    return ret;
}

int n;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    cin >> n;
    cout << pw(1378, n);
    /**/ return 0;
}
