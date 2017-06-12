#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 55
typedef long long ll;
typedef long double ld;
using namespace std;
int nt;
int n;
int a[N];
string c;

int main() {
    //freopen("in.in", "r", stdin); freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> n >> c;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (c == "Dee" && n == 1 && (a[1] % 2 == 0))
            cout << "Dee\n";
        else
            cout << "Dum\n";
    }
    return 0;
}

