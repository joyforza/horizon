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
int n, m;
vector <vector <int> > a;
vector <vector <int> > nxt;
int f[N];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        vector <int> tmp;
        vector <int> zero;
        for (int j = 0; j < m; j++) {
            int x;
            scanf("%d", &x);
            tmp.pb(x);
            zero.pb(0);
        }
        a.pb(tmp);
        nxt.pb(zero);
    }



    /// init
    f[n - 1] = n - 1;
    for (int j = 0; j < m; j++)
        nxt[n- 1][j] = n - 1;

    /// com
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++)
            if (a[i][j] <= a[i + 1][j]) nxt[i][j] = nxt[i + 1][j];
        else
            nxt[i][j] = i;

        f[i]= nxt[i][0];
        for (int j = 1; j < m; j++)
            f[i] = max(f[i], nxt[i][j]);
    }

    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << nxt[i][j] << " ";
        cout << "\n";
    } */


    int k;
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        if (f[l] >= r) printf("Yes\n");
        else
            printf("No\n");
    }
    /**/ return 0;
}

