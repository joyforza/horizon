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
#define M 10000001
typedef long long ll;
typedef long double ld;
using namespace std;
int n, a, b;
string s;


int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    cin >> n >> a >> b;
    cin >> s;

    if (s[b - 1] != s[a - 1]) {
        cout << 1;
    }
    else
        cout << 0;
    /**/ return 0;
}