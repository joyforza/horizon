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
#define N 100010
#define base 311097
#define MAXN 505
#define MAXE 1000001
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;
string a;
string b;
vector <int> pos[27];
int f[N];
int g[N];
int T[N];
int n;

void up(int x, int id) {
    while (x > 0) {
        T[x] = min(T[x], id);
        x = x - (x & (x ^ (x - 1)));
    }
}

int get(int x) {
    int ret = inf;
    while (x < N) {
        ret = min(ret, T[x]);
        x = x + (x & (x ^ (x - 1)));
    }
    return ret;
}

int main() {
    //freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> a;
    for (int i = 0; i < a.size(); i++) {
        pos[a[i] - 'a'].pb(i + 1);
    }
    cin >> b;
    n = b.size();

    for (int i = 1; i <= n; i++) f[i] = inf;
    f[0] = 0;

    for (int i = 0; i < b.size(); i++) {
        int st = f[i] + 1;
        int fn = a.size();

        int c = b[i] - 'a';
        int as = -1;

        int l = 0;
        int r = pos[c].size() - 1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pos[c][mid] >= st && pos[c][mid] <= fn) {
                as = pos[c][mid];
                r = mid - 1;
            }
            else
                if (pos[c][mid] < st) l = mid + 1;
            else
                r = mid - 1;
        }

        if (as == -1) {
            break;
        }
        f[i + 1] = as;
     }

  //  for (int i = 1; i <= n; i++)
  //      cout << f[i] << " ";
  //  cout << "\n";
  //  cout << "*****************************\n";


    for (int i = 1; i <= n; i++) g[i] = inf;
    g[n + 1] = a.size() + 1;

    for (int i = n; i >= 1; i--) {
        int st = 1;
        int fn = g[i + 1] - 1;

       // cout << st << " --> " << fn << "\n";

        int c = (b[i - 1] - 'a');
        int as = -1;

        int l = 0;
        int r = pos[c].size() - 1;

       // cout << b[i - 1] << "\n";
       // for (int j = 0; j < pos[c].size(); j++)
       //     cout << pos[c][j] << "\n";

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (pos[c][mid] >= st) {
                if (pos[c][mid] <= fn) {
                    as = pos[c][mid];
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }

        if (as == -1) {
            break;
        }
        g[i] = as;
    }

  //  for (int i = 1; i <= n; i++)
  //      cout << g[i] << " ";
  //  cout << "\n";

    /// init Tree
    for (int i = 1; i < N; i++) T[i] = inf;

    up(n + 1, n + 1);

    int st = -1;
    int fn = -1;
    int bl = inf;

    for (int i = n; i >= 0; i--) {
        if (f[i] != inf) {
            int L = i + 1;
            int R = get(f[i] + 1) - 1;

           // cout << "at position = " << i << "\n";
           // cout << L << " " << R << "\n";
            if (R - L + 1 < bl) {
                bl = R - L + 1;
                st = L;
                fn = R;
            }
        }
        if (g[i] != inf) up(g[i], i);
    }

    if (st == 1 && fn == n) cout << "-";
    else {
       // cout << "we del: " << st << " " << fn << "\n";
        st--;
        fn--;
        for (int i = 0; i < st; i++) cout << b[i];
        for (int i = fn + 1; i < n; i++) cout << b[i];
    }
    /**/ return 0;
}
