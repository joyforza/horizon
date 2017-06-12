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
#define N 300010
#define base 311097
#define MAXN 505
#define MAXE 1000001
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
const ll oo = (ll)1e18;

int a, b, c, m;
vector <int> s1;
vector <int> s2;
ll val;
ll tot1[N];
ll tot2[N];

bool canMake(int n1, int n2) {
    int g1 = min(n1, a);
    int g2 = min(n2, b);
    int g3 = n1 - g1 + n2 - g2;
    return (g3 <= c);
}

ll check(int x) {
    val = oo;
    for (int i = 0; i <= min(x, (int)s1.size()); i++) {
        int n1 = i;
        int n2 = x - i;
        if (n2 > s2.size()) continue;

        if (canMake(n1, n2)) {
       //     cout << n1 << " " << n2 << "\n";

            val = min(val, tot1[n1] + tot2[n2]);
        }
    }
    return val;
}

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> a >> b >> c;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        string tp;
        cin >> x >> tp;
        if (tp == "USB") s1.pb(x);
        else
            s2.pb(x);
    }
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    for (int i = 0; i < s1.size(); i++)
        tot1[i + 1] = tot1[i] + s1[i];
    for (int i = 0; i < s2.size(); i++)
        tot2[i + 1] = tot2[i] + s2[i];

//    check(4);
  //  cout << canMake(2, 1);

    int l = 0;
    int r = m;

    int num = 0;
    ll ret = 0;

    while (l <= r) {
        int mid = (l + r) >> 1;
        ll val = check(mid);
        if (val == oo) {
            r = mid - 1;
        }
        else {
            ret = val;
            num = mid;
            l = mid + 1;
        }
    }

    cout << num << " " << ret;
    /**/ return 0;
}
