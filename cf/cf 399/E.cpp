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
#define N 50005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

int dp[66][66];
int val[66];

int grundy(vector <int> st) {
    sort(st.begin(), st.end());
    if (st[0] > 0) return 0;
    for (int k = 0; k < st.size() - 1; k++)
        if (st[k + 1] - st[k] > 1) return st[k] + 1;
    return st[st.size() - 1] + 1;
}

vector <int> st;
int n, x;

int main() {
   // freopen("in.in", "r", stdin);
    freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);

    dp[0][0] = 0;
    for (int i = 1; i <= 60; i++)
    for (int j = 1; j <= i; j++) {

        st.clear();
        int rm = i - j;

        for (int k = 1; k <= rm; k++)
            st.pb(dp[rm][k]);

        if (j == i) st.pb(0);

        dp[i][j] = grundy(st);
    }


    for (int i = 1; i <= 60; i++) {
        st.clear();
        st.pb(0);
        for (int j = 1; j <= i; j++)
            st.pb(dp[i][j]);
        val[i] = grundy(st);
    }

    for (int i = 1; i <= 60; i++)
        cout << val[i] << "\n";

    int ok = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        ok ^= val[x];
      //  cout << val[x] << "\n";
    }
    if (ok > 0) cout << "NO";
    else
        cout << "YES";
    /**/ return 0;
}

