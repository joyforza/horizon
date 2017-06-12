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
int dp[50500][27];
int d[27];

bool check(int l, int r) {
    for (int i = 0; i < 26; i++)
        if (dp[r][i] - dp[l - 1][i] > 1) return false;
    return true;
}

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 26; j++)
            dp[i + 1][j] = dp[i][j] + (s[i] - 'A' == j);
    }

    int u = -1, v = -1;
    for (int i = 1; i <= s.size() - 26 + 1; i++) {
        int j = i + 26 - 1;
        if (j > s.size()) break;
        if (check(i, j)) {
            u = i;
            v = j;
            break;
        }
    }


    if (u == -1) cout << u;
    else{
        for (int i = u; i <= v; i++)
            if (s[i - 1] != '?')
            d[s[i - 1] - 'A']++;

        for (int i = u; i <= v; i++)
        if (s[i - 1] == '?') {
            for (int j = 0; j < 26; j++)
                if (d[j] == 0) {
                    s[i - 1] = char(j + 'A');
                    d[j]++;
                    break;
                }
        }
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '?') s[i] = 'A';
        cout << s;
    }
    /**/ return 0;
}
