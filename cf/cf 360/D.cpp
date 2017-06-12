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
int n, k;
bool f[N];
bool d[N];

int main() {
  //  freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x >= k) ok = true;
    }
    puts(ok ? "Yes" : "No");
   /**/ return 0;
}
