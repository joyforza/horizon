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
#define N 555
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
set<string> s;
string t;

int main() {
    //freopen("in.in", "r", stdin); // freopen("ou.ou", "w", stdout);
    cin >> t;
    s.insert(t);

    for (int i = 0; i < t.size(); i++) {
        int n = t.size() - 1;
        string tmp = t.substr(i + 1, n - i) + t.substr(0, i + 1);
       // cout << tmp << "\n";
        s.insert( tmp );
    }

    cout << s.size();
    /**/ return 0;
}
