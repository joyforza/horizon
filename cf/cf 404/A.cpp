#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 505
#define maxK 64
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
map<string, int> M;
int n;

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    M["Tetrahedron"] = 4;
    M["Cube"] = 6;
    M["Octahedron"] = 8;
    M["Dodecahedron"] = 12;
    M["Icosahedron"] = 20;
    cin >> n;
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        ret += M[s];
    }
    cout << ret;
    /**/ return 0;
}
