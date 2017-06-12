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
#define N 100100
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int last = -1;

char s[] = {'A', 'E', 'I', 'O', 'U', 'Y'};
string t;

bool check(char x) {
    for (int i = 0; i < 6; i++)
        if (x == s[i]) return true;
    return false;
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> t;
    int ret = 0;
    for (int i = 0; i < t.size(); i++)
        if (check(t[i])) {
            ret = max(ret, i - last);
            last = i;
        }

    ret = max((int)t.size() - last, ret);
    cout << ret;
    /**/ return 0;
}
