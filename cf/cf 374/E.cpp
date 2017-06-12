#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<double, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n, k, x;
double sum[N];
ll a[N];

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum[i] = sum[i - 1] + log10(a[i]);
    }

    int pos = -1;
    double best = sum[n];
    int tp = -1;

    for (int i = 1; i <= n; i++) {
        double val1 = - log(x) - log(k) - sum[n] + log10(a[i]);
        double val2 = log(x) + log(k) + sum[n] - log10(a[i]);

        if (sum[n] + val1 < best) {
            best = sum[n] + val1;
            tp = 1;
            pos = i;
        }

        if (sum[n] + val2 < best) {
            best = sum[n] + val2;
            tp = 2;
            pos = i;
        }
    }
    if (pos == -1) {
        for (int i = 1; i <= n; i++)
             cout << a[i] << " ";
    }
    else {
        if (tp == 1) {
            a[pos] -= (ll) k * x;
        }
        else
            a[pos] += (ll) k * x;
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
    }


    /**/return 0;
}
