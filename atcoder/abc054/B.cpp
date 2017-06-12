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
#define N 1000010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, m;
string a[55];
string b[55];

int countDay(int month) {
    if (month == 1 || month == 3 || month == 5 ||
    month = 7 || month == 8 || month == 10 || month == 12) return 31;
    if (month == 2) return 28;
    return 30;
}

bool check(int x, int y) {

    for (int i = 0; i < m; i++)
        for (int j = 0; j < m; j++) {
            if (a[x + i][y + j] != b[i][j]) return false;
    }
    return true;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < n - m + 1; i++)
        for (int j = 0; j < n - m + 1; j++)
            if (check(i, j)) {
                cout << "Yes";
                return 0;
            }
    cout << "No";

    /**/ return 0;
}

