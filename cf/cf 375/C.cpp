#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, pp>
#define pp3 pair<pp, int>
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
int n, m;
int a[2222];
int d[2222];
int b[2222];
vector <int> ps;


bool check(int x) {
      //  cout << "check : " << x << "\n";

        memset(d, 0, sizeof(d));
        ps.clear();

        for (int i = 1; i <= n; i++)
        if (a[i] > m) {
            ps.pb(i);
        }
        else {
            if (d[a[i]] < x) {
                d[a[i]]++;
            }
            else
                ps.pb(i);
        }

        int cnt = 0;
        for (int i = 1; i <= m; i++)
            cnt += (x - d[i]);
        return (cnt <= (int)ps.size());
}

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
       cin >> a[i];
    }

    int ret = -1;
    for (int i = 0; i <= n; i++)
        if (!check(i)) break;
        else
            ret = i;

    cout << ret << " ";
    check(ret);
    int rr = 0;
    for (int i = 1; i <= m; i++)
    for (int j = 1; j <= ret - d[i]; j++) {
        a[ps[rr]] = i;
        rr++;
    }
    cout << rr << "\n";
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    /**/return 0;
}
