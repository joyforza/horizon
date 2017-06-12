#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200020
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, k;
int a[N];
vector <int> pos;
vector <int> c1;
int c2 = -1;

int main() {

    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int dem = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= 0) a[i] = 1;
        else {
            a[i] = 0;
            dem++;
            pos.pb(i);
        }
    }
    if (dem > k) {
        cout << -1;
        return 0;
    }

    k -= dem;

    if (dem == 0) {
        cout << 0;
        return 0;
    }

    int cnt = 0;
    int ls = -1;

    int tot = 1;

    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            if (ls == -1) ls = i;
            cnt++;
        }
        else
        if (cnt > 0) {
            if (ls != 1) {
                c1.pb(cnt);
                tot += 2;
            }
            cnt = 0;
            ls = -1;
        }
    }
    if (cnt > 0) {
            c2 = cnt;
            tot++;
    }

    sort(c1.begin(), c1.end());


    for (int i = 0; i < c1.size(); i++) {
        if (k >= c1[i]) {
            k -= c1[i];
            tot -= 2;
        }
    }

    if (c2 != -1) {
        if (k >= c2) {
            k -= c2;
            tot--;
        }
    }

    cout << tot;
    /**/ return 0;
}
