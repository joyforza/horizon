#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 200010
#define mod 1000000007
typedef long long ll;
using namespace std;
int nt = 100;

int main() {
	freopen("in.in", "w", stdout);
	//freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cout << nt << "\n";
    while (nt--) {
        cout << (rand() % 1000) + 1 << " " << (rand() % 100) + 1 << " " << 10000 << "\n";
    }
    return 0;
}
