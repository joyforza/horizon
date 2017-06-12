#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 100010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int n, f;
vector <int> a;

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> n >> f;
    ll ret = 0;
    for (int i = 1; i <= n; i++) {
        int k, c;
        cin >> k >> c;
        if (c > k) {
            ret += k;
            int rr = c - k;
            a.pb(min(rr, k));
        }
        else {
            ret += c;
        }
    }
    sort(a.begin(), a.end());
    for (int i = a.size() - 1; i >= 0; i--) {
        if (f == 0) break;
        ret += a[i];
        f--;
    }
    cout << ret;
    /**/return 0;
}
