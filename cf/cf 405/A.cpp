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
#define N 505
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int n, k;

void extendEcliud(int A, int B) {
	if (B == 0) {
		x = A;
		y = 0;
	}
	else {
		extendEcliud(B, A % B);
		x = y;
		y = x - (A / B) * y;
	}
}

int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> k;
    int ret = inf;

    for (int i = 1; i < (1 << 20); i++) {
    	ll val = 0;
    	for (int j = 20; j >= 0; j--)
    		if ((i >> j) & 1)
    			val = (val * 10 + k) % n;
    		else
    			val = (val * 10) % n;

    	if (val == 0) ret = min(ret, i);
    }

    for (int i = 20; i >= 0; i--)
    	if ((ret >> i) & 1) {
    		
    	}
    /**/ return 0;


}

