#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 1010
typedef long long ll;
typedef long double ld;
using namespace std;
int n;

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    while (nt--) {
        cin >> n;
        int tot = 0;
        bool ok1 = true;
        bool ok2 = false;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            tot += x;
            if (x < 3)
                ok1 = false;
            if (x == 5)
                ok2 = true;
        }

        if (ok1 && ok2 && tot >= 4 * n)
            puts("Yes");
        else
            puts("No");
    }
   /**/ return 0;
}
