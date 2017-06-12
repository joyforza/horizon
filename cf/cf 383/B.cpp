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
#define N 100010
#define base 311097
#define M 10000001
typedef long long ll;
typedef long double ld;
using namespace std;
int n, x;
int a[N];
int T[N];


int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ll cnt = 0;
    T[a[1]]++;
    for (int i = 2; i <= n; i++) {
        ll val = x ^ a[i];
        if (val <= 100000) {
            cnt += T[(int)val];
        }
        T[a[i]]++;
    }
    cout << cnt;

    /**/ return 0;
}
