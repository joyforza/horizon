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
#define N 256
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
string s;
int n;
bool f[55];

bool check(string s) {
    for (int i = 0; i < s.size(); i++)
        if (f[s[i] - 'a'] == false) return false;
    return true;
}

int main() {
//    freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.size(); i++)
        f[s[i] - 'a'] = true;

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        puts(check(s) ? "Yes" : "No");
    }
    /**/ return 0;
}
