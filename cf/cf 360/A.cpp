#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 1000001
typedef long long ll;
typedef long double ld;
using namespace std;
int n, d;
string s;

bool check(string a) {
    for (int i = 0; i < a.size(); i++)
        if (a[i] == '0') return true;
    return false;
}

int main() {
  //  freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int ret = 0;
    int cur = 0;
    cin >> n >> d;
    for (int i = 0; i < d; i++) {
        cin >> s;
        if (check(s)) {
            cur++;
        }
        else {
                ret = max(ret, cur);
            cur = 0;
        }
    }
    ret = max(ret, cur);
    cout << ret;
   /**/ return 0;
}
