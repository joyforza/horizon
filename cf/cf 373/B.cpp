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
int n;
string s;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    //p1
    int d1 = 0;
    int d2 = 0;
    for (int i = 0; i < s.size(); i += 2)
    if (s[i] != 'r') {
        d1++;
    }
    for (int i = 1; i < s.size(); i+= 2)
    if (s[i] != 'b') {
        d2++;
    }
    int ret = max(d1, d2);

    d1 = 0;
    d2 = 0;
    for (int i = 0; i < s.size(); i+= 2)
        if (s[i] != 'b') d1++;
    for (int i = 1; i < s.size(); i+=2)
        if (s[i] != 'r') d2++;

    ret = min(ret, max(d1, d2));
    cout << ret;

    /**/ return 0;
}
