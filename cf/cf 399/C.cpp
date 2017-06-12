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
#define N 5005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, k, x;
int d[N];
int f[N];

int main() {
   // freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k >> x;

    for (int i = 1; i <= n; i++) {
        int val;
        cin >> val;
        d[val]++;
    }



    for (int i = 1; i <= k; i++) {
        memset(f, 0, sizeof(f));
        int bg = 1;
        //cout << "at: " << i << "\n";

        for (int j = 0; j <= 3000; j++)
            if (d[j] > 0) {


                f[j] += d[j] / 2;
                f[j ^ x] += d[j] / 2;

                if (d[j] % 2 != 0) {
                    if (bg == 0) f[j]++;
                    else
                        f[j ^ x]++;
                }

                if (d[j] % 2 != 0) bg = 1 - bg;


            }

        for (int j = 0; j <= 3000; j++)
            d[j] = f[j];
    }


    int rmax = -inf;
    int rmin = inf;
    for (int i = 0; i <= 3000; i++)
    if (d[i] > 0) {
        rmax = max(rmax, i);
        rmin = min(rmin, i);
    }

    cout << rmax << " " << rmin;

    /**/ return 0;
}

