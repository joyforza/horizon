#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define inf 1000000001
#define mod 1000000007
typedef long long ll;
using namespace std;
int n;
map<string, int> M;
map<string, int> N;
string s;

int main() {
	freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
	int ret = inf;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<string> rr;
        cin >> s;
        int m = s.size();
        rr.pb(s);
        M.clear();
        for (int j = 1; j < m; j++) {
            string tmp = s.substr(0, j) + s.substr(j, m - j);
            rr.pb(tmp);
            M[tmp] = inf;
        }

        for (int j = 0; j < rr.size(); j++)
            M[rr[j]] = min(M[rr[j]], j);

        for (int j = 0; j < rr.size(); j++) {
            if (i > 0 && !N.count(rr[j])) {
                cout << "-1";
                return 0;
            }
            N[rr[j]] += M[rr[j]];
            if (i == n - 1)
                ret = min(ret, N[rr[j]]);
        }
    }
    cout << ret;
    return 0;
}
