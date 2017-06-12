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
int nt;
string s;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1') cnt++;
        puts((cnt == 1 || s.size() - cnt == 1) ? "Yes" : "No");
    }
    /**/ return 0;
}
