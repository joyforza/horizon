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
bool s[N];
int col[N];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 2; i < N; i++)
    if (s[i] == false) {
        for (int j = i + i; j < N; j += i)
            s[j] = true;
    }


    if (n <= 2) cout << 1 << "\n";
    else
        cout << 2 << "\n";

    for (int i = 2; i <= n + 1; i ++)
        if (s[i]) cout << 2 << " " ;
    else
        cout << 1 << " ";
    /**/ return 0;
}

