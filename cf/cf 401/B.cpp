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
#define N 100005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
string s;
vector <int> a;
vector <int> b;
bool f[1010];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    for (int i = 0; i < s.size(); i++) a.pb(s[i] - '0');
    cin >> s;
    for (int i = 0; i < s.size(); i++) b.pb(s[i] - '0');

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());


    int num = 0;
    int oh = 0;

    /// max num
    for (int i = b.size() - 1; i >= 0; i--) {

        bool ok = false;
        for (int j = a.size() - 1; j >= 0; j--)
        if (f[j] == false && b[i] > a[j]) {
            num++;
            f[j] = true;
            ok = true;
            break;
        }

        if (ok) continue;

        for (int j = a.size() - 1; j >= 0; j--)
        if (f[j] == false) {
            f[j] = true;
            break;
        }
    }
    /// min oh
    memset(f, false, sizeof(f));

    for (int i = b.size() - 1; i >= 0; i--) {
        bool ok = false;
        for (int j = a.size() - 1; j >= 0; j--)
        if (f[j] == false && b[i] >= a[j]) {
            f[j] = true;
            ok = true;
            break;
        }
        if (ok) continue;
        if (!ok) {
            for (int j = a.size() - 1; j >= 0; j--)
            if (f[j] == false) {
                f[j] = true;
                oh++;
                break;
            }
        }
    }
    cout << oh << "\n" << num;
    /**/ return 0;
}

