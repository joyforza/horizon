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
int n;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> s;
        n = s.size();
        bool ok = true;

        for (int i = 0; i < n / 2; i++) {
            int j = n - i - 1;
            if (s[i] == '.' && s[j] == '.') {
                s[i] = 'a';
                s[j] = 'a';
            }
            else
                if (s[i] == '.') s[i] = s[j];
            else
                if (s[j] == '.') s[j] = s[i];
            else
            if (s[i] != s[j]) {
                ok = false;
                break;
            }
        }
        for (int i = 0; i < s.size(); i++)
            if (s[i] == '.') s[i] = 'a';

        if (ok) cout << s << endl;
        else
            cout << "-1\n";
    }

    /**/ return 0;
}
