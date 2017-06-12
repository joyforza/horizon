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
#define N 100010
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
map <char, int> M;

int main() {
    //freopen("in.in", "r", stdin);
    M['A'] = 4;
    M['K'] = 3;
    M['Q'] = 2;
    M['J'] = 1;
    M['X'] = 0;
    int n;
    cin >> n;
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < s.size(); j++)
            ret += M[s[j]];
    }
    cout << ret;
    /**/ return 0;
}
