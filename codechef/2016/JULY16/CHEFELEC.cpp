#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100010
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
string s;
int x[N];

int main() {
    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int nt;
    cin >> nt;
    while (nt--) {
        cin >> n;
        cin >> s;
        for (int i = 1; i <= n; i++)
            cin >> x[i];
        s = '1' + s + '1';
        x[0] = -1000000001;
        x[n + 1] = 2000000001;
        ll ret = 0;
        int st;
        for (int i = 1; i <= n; i++)
        if (s[i] == '0') {
            if (s[i - 1] == '1') st = i;
            if (s[i + 1] == '1') {
                int best = 2000000001;
                for (int j = st; j <= i; j++)
                    best = min(best, x[j] - x[st - 1] + x[i + 1] - x[j + 1]);
                for (int j = i; j >= st; j--)
                    best = min(best, x[i + 1] - x[j] + x[j - 1] - x[st - 1]);
                ret += best;
            }
        }
        cout << ret << endl;
    }
   /**/ return 0;
}
