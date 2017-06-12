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
#define N 50005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
map <string, int> M;
int f[222][222];
int cnt = 1;
string s;

int get(string s) {
    if (M[s] == 0)
        M[s] = ++cnt;
    return M[s];
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    M[s] = 1;

    for (int i = 1; i <= n; i++) {
       cin >> s;
       string t1 = "";
       string t2 = "";
       for (int j = 0; j < 3; j++) t1 = t1 + s[j];
       for (int j = 5; j < 8; j++) t2 = t2 + s[j];
       f[get(t1)][get(t2)]++;
       //cout << t1 << "\n";
       //cout << t2 << "\n";
    }

    for (int i = 1; i <= 100; i++)
        for (int j = 1; j <= 100; j++)
    if (f[i][j] - f[j][i] != 0) {
        cout << "contest";
        return 0;
    }

    cout << "home";
    /**/ return 0;
}

