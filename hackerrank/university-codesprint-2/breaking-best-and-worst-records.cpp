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
#define N 50005
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n;
int a[1010];

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;
    int x;
    cin >> x;
    int MaxVal = x;
    int MinVal = x;

    int retMax = 0;
    int retMin = 0;

    for (int i = 1; i < n; i++) {
        cin >> x;
        if (x > MaxVal) {
            retMax++;
            MaxVal = x;
        }
        if (x < MinVal) {
            retMin++;
            MinVal = x;
        }
    }

    cout << retMax << " " << retMin;
    /**/ return 0;
}

