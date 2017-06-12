#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 100010
#define mod 1000000007
typedef long long ll;
using namespace std;
int n, k, p, m;
int a[N];
string s;
int cnt[N];
int cntB[N];
int T[N];
int G[N];
priority_queue <pp> qu; /// (val / last)

int getVal() {
    while (!qu.empty() && qu.top().se > n) qu.pop();
    if (qu.empty()) return 0;
    else
        return qu.top().fi;
}

int rot[N];

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k >> p;
    k = min(k, n);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[i] = cnt[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
    if (i < k) T[i] = cnt[i];
    else
        T[i] = max(T[i - 1], cnt[i] - cnt[i - k]);

    rot[0] = T[n];
    int cntRol = 0;

    int sn = n;

    cin >> s;

    int dd = 0;

    for (int i = 0; i < s.size(); i++)
    if (s[i] == '?') {

        if (cntRol >= sn) {
          //  cout << cntRol << " " << cntRol - n << "\n";
            cout << rot[cntRol % sn] << "\n";
        }
        else
            cout << rot[cntRol] << "\n";

    }
    else {
        cntRol++;
     //   cout << "cnt = " << cntRol << "\n";
        if (cntRol >= sn) continue;

        m++;
        cntB[m] = cntB[m - 1] + a[n];
        n--;
        if (m < k) {
            int mx = k - m;
            qu.push(mp(cntB[m] + cnt[mx], mx));
            G[m] = cntB[m];
        }
        else {
            G[m] = max(G[m - 1], cntB[m] - cntB[m - k]);
        }
        rot[cntRol] = max(getVal(), max(G[m], T[n]));
       // cout << "n = " << n << "\n";
    }

   // for (int i = 0; i < sn; i++) cout << rot[i] << " ";
   // cout << "\n";

    return 0;
}
