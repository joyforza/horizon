#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, pp>
#define pp3 pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
string s;

bool ok(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    s = s + '_';
    int last = -1;
    bool op = false;

    int len = 0;
    int num = 0;


    for (int i = 0; i < s.size(); i++) {
        if (ok(s[i])) {
            if (last == -1) {
                last = 1;
            }
            else
                last++;
        }
        else {
            if (last > 0) {
                if (op == false) len = max(len, last);
                    else
                        num++;
                last = -1;
            }
            if (s[i] == '(') op = true;
            if (s[i] == ')') op = false;
        }

    }
    cout << len << " " << num;
    /**/return 0;
}
