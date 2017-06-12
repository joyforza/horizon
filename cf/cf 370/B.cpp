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
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
string s;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;
    int u = 0;
    int d = 0;
    int l = 0;
    int r = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'U') u++;
        if (s[i] == 'D') d++;
        if (s[i] == 'L') l++;
        if (s[i] == 'R') r++;
    }

    if (s.size() % 2 != 0)
        cout << -1;
    else {
        int cost = inf;

      //  cout << s.size() / 2 << "\n";
        for (int i = 0; i <= s.size() / 2; i++) {
            int add = 0;
            add += abs(u - i);
            add += abs(d - i);
            add += abs((int)s.size()/2 - i - l);
            add += abs((int)s.size()/2 - i - r);
            cost = min(cost, add / 2);
           // cout << add << "\n";
        }
        cout << cost << "\n";
    }
    /**/ return 0;
}
