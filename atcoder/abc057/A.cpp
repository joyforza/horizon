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
#define N 1000010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
ll a[55];
int l, r;

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> l >> r;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    double ret = 0;
    int num = 0;
    for (int d = l; d <= r; d++) {
        for (int i = 1; i <= n - d + 1; i++) {
            
            double val;
            if (d % 2 != 0)
              val =  a[i + d / 2 - 1];
            else
              val = ((double)a[i + d / 2 - 1] + a[i + d / 2]) / 2;
          
            if (val > ret) {
                ret = val;
                num = 1;
            }
            else
              if (val == ret) num++;
        }
    }

    printf("%.6lf\n", ret);
    printf("%d", num);
    /**/ return 0;
}

