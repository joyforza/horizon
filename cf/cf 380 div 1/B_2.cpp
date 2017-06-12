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
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n, a, b, k;
string s;
priority_queue<ppp> qu;
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
            qu.push(mp(i - ls, mp(ls + 1, i)));
            tot += ((i - ls) / b);
        }
        ls = i + 1;
    }

    while (tot >= a) {
        int len = qu.top().fi;

        int l = qu.top().se.fi;
        int r = qu.top().se.se;

        int pos = l + b - 1;
        ret.pb(pos);

        int s1 = pos - l;
        int s2 = r - pos;

        qu.pop();

        tot = tot - (len / b) + (s1 / b) + (s2 / b);

        if (s1 >= b) {
            qu.push(mp(s1, mp(l, pos - 1)));
        }

        if (s2 >= b) {
            qu.push(mp(s2, mp(pos + 1, r)));
        }
    }

    cout << ret.size() << "\n";
    for (int i = 0; i < ret.size(); i++)
        cout << ret[i] << " ";

    /**/ return 0;
}
