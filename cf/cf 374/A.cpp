#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
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
vector <int> ret;

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    s = s + 'W';
    int cnt = -1;

    for (int i = 0; i < s.size(); i++)
    if (s[i] == 'B') {
        if (cnt == -1) cnt = 1;
        else
            cnt++;
    }
    else
    if (s[i] == 'W') {
        if (cnt != -1) {
            ret.pb(cnt);
            cnt = -1;
        }
    }
    cout << ret.size() << endl;
    for (int i = 0; i < ret.size(); i++) cout << ret[i] << " ";
    /**/return 0;
}
