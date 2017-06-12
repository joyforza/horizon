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

priority_queue<int> qu;
int nt;
int n, k;
string s;

int main() {
   // freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while(nt--) {
        cin >> n >> k;
        cin >> s;
        s = s + '#';
        // remove all queue
        while(!qu.empty()) qu.pop();

        int cnt = 0;
        int twice = 0;

        for (int i = 0; i < n; i++) {
            cnt++;
            if (s[i] != s[i + 1]) {
                if (cnt > 2) qu.push(cnt);
                twice += (cnt == 2);
                cnt = 0;
            }
        }

        for (int i = 1; i <= k; i++) {
            // break the best
            if (qu.empty()) break;
            int val = qu.top();
            qu.pop();
            int d1 = val / 2;
            int d2 = val / 2 - (val % 2 == 0);
            if (d1 > 2) qu.push(d1);
            else
                if (d1 == 2) twice++;

            if (d2 > 2) qu.push(d2);
            else
                if (d2 == 2) twice++;
        }

        int ret = inf;
        if (qu.empty()) {
            if (twice > 0) ret = 2;
            else
                ret = 1;
        }
        else
            ret = qu.top();
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
