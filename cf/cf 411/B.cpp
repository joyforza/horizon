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

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int cnt = 0;
    cin >> s;
    while (true) {
        int pos = -1;
        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == 'a' && s[i + 1] == 'b') {
                pos = i;
                break;
            }
        }
        if (pos == -1) break;
        int n = s.size();
        s = s.substr(0, pos) + "bba" + s.substr(pos + 2, n - pos - 2);
        cout << s << "\n";
        cnt++;
    }
    cout << "total = " << cnt << "\n";
	return 0;
}
