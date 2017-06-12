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
#define M (1 << 16) + 1
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt;
int n, k;
string s;
vector<int> v;

int need(int len, int x) {
    if (len <= x) return 0;
    return (len / (x + 1));
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while(nt--) {
        cin >> n >> k;
        cin >> s;
        s = s + '#';

        v.clear();

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt++;
            if (s[i] != s[i + 1]) {
                v.pb(cnt);
                cnt = 0;
            }
        }

        int l = 2;
        int r = n;
        int ret = n;

        while (l <= r) {
            int mid = (l + r)  >> 1;

            int tot = 0;
            for (int i = 0; i < v.size(); i++)
                tot += need(v[i], mid);

            if (tot <= k) {
                ret = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }

        // special case
        int mask1, mask2;
        int cn1 = 0;
        int cn2 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                mask1 = 1;
                mask2 = 0;
            }
            else {
                mask1 = 0;
                mask2 = 1;
            }
            int c = s[i] - '0';
            if (c != mask1) cn1++;
            if (c != mask2) cn2++;
        }
        if (min(cn1, cn2) <= k) ret = 1;

        cout << ret << "\n";
    }
    /**/ return 0;
}
