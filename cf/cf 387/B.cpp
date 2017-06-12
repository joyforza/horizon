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
#define N 555
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
string s;
vector <int> pos;

int main() {

    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    cin >> n;
    cin >> s;
    int da = 0;
    int dg = 0;
    int dt = 0;
    int dc = 0;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') da++;
        if (s[i] == 'G') dg++;
        if (s[i] == 'T') dt++;
        if (s[i] == 'C') dc++;
        if (s[i] == '?') {
            cnt++;
            pos.pb(i);
        }
    }
    int ac = max(max(da, dg), max(dt, dc));


    /// A
    if (cnt < ac - da) {
            cout << "===";
            return 0;
    }

    cnt -= (ac - da);
    for (int i = 1; i <= ac - da; i++) {
        s[pos[pos.size() - 1]] = 'A';
        pos.pop_back();
    }

    /// C
    if (cnt < ac - dc) {
            cout << "===";
            return 0;
    }
    cnt -= (ac - dc);
    for (int i = 1; i <= ac - dc; i++) {
        s[pos[pos.size() - 1]] = 'C';
        pos.pop_back();
    }
    /// T

    if (cnt < ac - dt) {
            cout << "===";
            return 0;
    }
    cnt -= (ac - dt);
    for (int i = 1; i <= ac - dt; i++) {
        s[pos[pos.size() - 1]] = 'T';
        pos.pop_back();
    }

    /// G

    if (cnt < ac - dg) {
            cout << "===";
            return 0;
    }
    cnt -= (ac - dg);
    for (int i = 1; i <= ac - dg; i++) {
        s[pos[pos.size() - 1]] = 'G';
        pos.pop_back();
    }

    /// remain
    if (cnt % 4 != 0) {
        cout << "===";
        return 0;
    }

    for (int i = 1; i <= cnt / 4; i++) {
        s[pos[pos.size() - 1]] = 'A';
        pos.pop_back();
        s[pos[pos.size() - 1]] = 'C';
        pos.pop_back();
        s[pos[pos.size() - 1]] = 'T';
        pos.pop_back();
        s[pos[pos.size() - 1]] = 'G';
        pos.pop_back();
    }

    cout << s;
     /**/ return 0;
}
