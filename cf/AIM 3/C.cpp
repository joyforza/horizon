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
#define N 501
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
string s;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;
    int st = 0;
    while (st < s.size() && s[st] == 'a') st++;
    if (st == s.size()) {
        for (int i = 0; i < s.size() - 1; i++)
            cout << 'a';
        cout << 'z';
    }
    else {
        for (int i = 0; i < st; i++)
            cout << s[i];
        bool dec = true;

        for (int i = st; i < s.size(); i++) {
            if (s[i] == 'a') {
                dec = false;
            }
            if (dec)
                cout << char(s[i] - 1);
            else
                cout << s[i];
        }
    }
    /**/ return 0;
}
