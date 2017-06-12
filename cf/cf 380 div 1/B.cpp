#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, a, b, k;
string s;
vector <pp> cc;
vector <int> ret;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> a >> b >> k;
    cin >> s;
    s = s + '1';
    int ls = 0;
    int tot = 0;

    for (int i = 0; i < s.size(); i++)
    if (s[i] == '1') {
        if (i - ls >= b) {
            cc.pb(mp(ls + 1, i));
            tot += ((i - ls) / b);
        }
        ls = i + 1;
    }
    int cur = 0;

    while (tot >= a) {
        int l = cc[cur].fi;
        int r = cc[cur].se;

        ret.pb(l + b - 1);
        tot--;

        if (r - l + 1 < b) cur++;
        else
            cc[cur] = mp(l + b, r);
    }

    cout << ret.size() << "\n";
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << " ";
    /**/ return 0;
}
