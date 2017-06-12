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
#define N 300005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m, k;
int s[10000011];
int can[10000011];
vector <int> a[1000010];
int M[10000001];
vector <int> ret;
vector <int> st;

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        x++;
        s[x]++;
    }

    int add = 0;
    for (int i = 10000000; i >= 1; i--) {
        s[i] += add;
        add = 0;
        if (s[i] >= k) {
            add += (s[i] - k);
            can[i] = 0;
        }
        else {
            can[i] = k - s[i];
        }
    }
    if (add > 0) {
        printf("-1");
        return 0;
    }


    memset(s, 0, sizeof(s));
    int cnt = 0;
    for (int i = 1; i <= m; i++) {
        int x;
        scanf("%d", &x);
        x++;
        s[x]++;
        if (M[x] == 0) {
            M[x] = ++cnt;
        }
        a[M[x]].pb(i);
    }


    for (int i = 1; i <= 10000000; i--) {
        int id = M[i];
        for (int j = 0; j < (int)a[id].size(); j++)
            st.pb(a[id][j]);

        for (int j = 0; j < min(can[i], (int)st.size()); j++) {
            ret.pb(st[st.size() - 1]);
            st.pop_back();
        }
    }

    printf("%d\n", ret.size());
    for (int i = 0; i < ret.size(); i++)
        printf("%d ", ret[i]);
    /**/ return 0;
}

