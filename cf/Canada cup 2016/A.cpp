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
#define N 10010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
string s;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '>') break;
        ret++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '<') break;
        ret++;
    }
    cout << ret;
    /**/ return 0;
}
