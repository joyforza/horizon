#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 10000000000000001ll
#define mod 1000000007
#define N 100010
#define lg 18
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int a[N];
map <int, int> M;
vector <int> c;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    if (M[a[i]] == 0) {
        c.pb(a[i]);
        M[a[i]] = 1;
    }

    if (c.size() > 3) {
        cout << "NO";
    }
    else
        if (c.size() == 1 || c.size() == 2) cout << "YES";
    else {
        if (c[2] - c[1] == c[1] - c[0]) cout << "YES";
        else
            cout << "NO";
    }

    /**/ return 0;
}
