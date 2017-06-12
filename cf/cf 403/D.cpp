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
#define N 300005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

string a[1010];
string b[1010];

vector <int> c[1010];
bool f[1010];
map<string, int> M;

string ret[1010];

vector <int> d;

int n;

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];

    int dem = 0;
    for (int i = 1; i <= n; i++)
    if (f[i] == false) {
        dem++;
        c[dem].pb(i);
        f[i] = true;

        for (int j = 1; j <= n; j++)
            if (f[j] == false) {

                if (a[j].substr(0, 3) == a[i].substr(0, 3)) {
                    c[dem].pb(j);
                    f[j] = true;
                }
            }
    }

    bool ok = true;

    for (int i = 1; i <= dem; i++)
    if (c[i].size() > 1) {

       // cout << i << "\n";

        for (int j = 0; j < c[i].size(); j++) {
            int pos = c[i][j];
            ret[pos] = a[pos].substr(0, 2) + b[pos][0];
            if (M.count(ret[pos])) {
                cout << "NO";
                return 0;
            }
            M[ret[pos]] = 1;

           // cout << c[i][j] << " ";
        }
      //  cout << "\n";
    }
    else {
        d.pb(c[i][0]);
    }

    for (int i = 1; i <= dem; i++) c[i].clear();
    dem = 0;
    memset(f, false, sizeof(f));

    for (int i = 0; i < d.size(); i++)
    if (f[i] == false) {
        dem++;
        f[i] = true;
        c[dem].pb(d[i]);

        for (int j = i + 1; j < d.size(); j++)
        if (f[j] == false) {
            int p1 = d[i];
            int p2 = d[j];
            string s1 = (a[p1].substr(0, 2) + b[p1][0]);
            string s2 = (a[p2].substr(0, 2) + b[p2][0]);
            if (s1 == s2) {
                f[j] = true;
                c[dem].pb(d[j]);
            }
        }
    }

    d.clear();

    for (int i = 1; i <= dem; i++)
    if (c[i].size() > 1) {
        for (int j = 0; j < c[i].size(); j++) {
            int pos = c[i][j];
            ret[pos] = a[pos].substr(0, 3);
            if (M.count(ret[pos])) {
                cout << "NO";
                return 0;
            }
            M[ret[pos]] = 1;
        }
    }
    else {
        d.pb(c[i][0]);
    }

    memset(f, false, sizeof(f));

    for (int i = 0; i < d.size(); i++)
    if (f[i] == false) {
        int pos = d[i];
        string s1 = a[pos].substr(0, 3);
        string s2 = a[pos].substr(0, 2) + b[pos][0];

        if (M.count(s1) && M.count(s2)) {
            cout << "NO";
            return 0;
        }
        else
        if (M.count(s1)) {
            ret[pos] = s2;
            M[ret[pos]] = 1;
            f[i] = true;
        }
        else
        if (M.count(s2)){
            ret[pos] = s1;
            M[ret[pos]] = 1;
            f[i] = true;
        }
    }

    for (int i = 0; i < d.size(); i++)
    if (f[i] == false) {
        int pos = d[i];
        string s1 = a[pos].substr(0, 3);
        string s2 = a[pos].substr(0, 2) + b[pos][0];

        if (M.count(s1) && M.count(s2)) {
            cout << "NO";
            return 0;
        }
        if (M.count(s1)) {
            ret[pos] = s2;
            M[ret[pos]] = 1;
        }
        else
        {
            ret[pos] = s1;
            M[ret[pos]] = 1;
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; i++)
        cout << ret[i] << "\n";

    /**/ return 0;
}

