#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 1000010
#define mod 1000000007
typedef long long ll;
using namespace std;
string s;
vector<int> pos;

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;
    int n = s.size();
    for (int i = 0; i < s.size(); i++)
    if (s[i] == 'a') {
        pos.pb(i + 1);
    }

    int num = 0;
    int ret = 0;
    for (int i = pos.size() - 1; i >= 0; i--) {
        int rr = pos[i];
        if (i == pos.size() - 1) {
            ret += (n - rr);
            num += (n - rr);
        }
        else {
            num = num * 2 % mod;
            num = (num + (pos[i + 1] - pos[i] - 1)) % mod;
            ret = (ret + num) % mod;
        }
    }
    cout << ret;
	return 0;
}
