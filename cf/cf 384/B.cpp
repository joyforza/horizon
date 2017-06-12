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
#define N 100010
#define base 311097
#define M 10000001
typedef long long ll;
typedef long double ld;
using namespace std;

int n;
ll k;

int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    cin >> n >> k;
    if (k % 2 != 0) {
        cout << 1;
    }
    else {
        for (int i = 1; i < n; i++) {
            ll jmp = (1LL << (i + 1));

            ll del = (1LL << i) - 1;

           // cout << del << "\n";

            ll pos = k - del;


            if (pos % jmp == 1) {
                cout << (i + 1);
                return 0;
            }
        }
    }
    /**/ return 0;
}
