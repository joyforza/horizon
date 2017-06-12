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
int n, h;

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> n >> h;
   // double A = 0.5 * h;

    //cout << A << "\n";

    for (int i = 1; i < n; i++) {

        double bx = 1.0 * i / n;
        bx = bx * h * h;
        double es = sqrt(bx);

        printf("%.10lf ", es);
    }
    /**/return 0;
}
