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
int st, fn;
vector <int> ret;

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> st >> fn;

    while (fn > st) {
        ret.pb(fn);
        if (fn % 2 != 0) {

            if (fn % 10 != 1) {
                cout << "NO";
                return 0;
            }

            fn /= 10;
        }
        else {
            fn /= 2;
        }
    }
    if (fn != st) {
        cout << "NO";
        return 0;
    }

    ret.pb(st);
    cout << "YES\n";
    cout << ret.size() << "\n";
    for (int i =  ret.size() - 1; i >= 0; i--)
        cout << ret[i] << " ";
    /**/return 0;
}
