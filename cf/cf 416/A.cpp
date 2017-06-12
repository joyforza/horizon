#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 100010
#define mod 1000000007
#define inf 1000000001
#define esp 1e-9
typedef long long ll;
using namespace std;
int a, b;

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> a >> b;
    int d = 1;
    for (int i = 1; ;i++) {
        if (i & 1) {
            if (a < d) {
                cout << "Vladik";
                break;
            }
            a -= d;
        }
        else {
            if (b < d) {
                cout << "Valera";
                break;
            }
            b -= d;
        }
        d++;
    }
    /**/return 0;
}
