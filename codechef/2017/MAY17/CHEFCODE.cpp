#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 55
#define mod 1000000007
typedef long long ll;
using namespace std;
int n;
ll a[N], k;
vector <ll> sa;
vector <ll> sb;

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int m = n / 2;
    for (int i = 1; i < (1 << m); i++) {
        ll val = 1;
        for (int j = 0; j < m; j++)
        if ((i >> j) & 1) {
            if (val > k / a[j + 1])
                val = k + 1;
            else
                val = val * a[j + 1];
        }
        sa.pb(val);
    }
    sort(sa.begin(), sa.end());
    int nn = n - m;
    for (int i = 1; i < (1 << nn); i++) {
        ll val = 1;
        for (int j = 0; j < nn; j++)
        if ((i >> j) & 1) {
            if (val > k / a[m + j + 1]) val = k + 1;
            else
                val = val * a[m + j + 1];
        }
        sb.pb(val);
    }
    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());


    ll tot = 0;

    for (int i = 0; i < sa.size(); i++) {
       // cout << sa[i] << " ";
        if (sa[i] <= k) tot++;
    }
    //cout << "\n";
    for (int i = 0; i < sb.size(); i++) {
        if (sb[i] <= k) tot++;
      //  cout << sb[i] << " ";
    }
    //cout << "\n";

    for (int i = 0; i < sa.size(); i++) {
        ll need = k / sa[i];
        int l = 0;
        int r = sb.size() - 1;
        int ret = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (sb[mid] <= need) {
                ret = mid + 1;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        if (ret != -1) tot += ret;
    }
    cout << tot;
	return 0;
}
