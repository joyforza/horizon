#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, pp>
#define pp3 pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int x, y, z;
int a[5555];

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n;

    cout << "? 1 2" << endl;
    fflush(stdout);
    cin >> x;
    cout << "? 2 3" << endl;
    fflush(stdout);
    cin >> y;
    cout << "? 1 3" << endl;
    fflush(stdout);
    cin >> z;

    a[2] = (x + y - z) / 2;
    a[1] = x - a[2];
    a[3] = z - a[1];

    for (int i = 4; i <= n; i++) {
        cout << "? " << i - 1 << " " << i << endl;
        fflush(stdout);
        cin >> z;
        a[i] = z - a[i - 1];
    }

    cout << "! ";
    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    fflush(stdout);
    /**/return 0;
}
