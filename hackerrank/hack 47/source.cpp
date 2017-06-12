#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 501
#define base 311097
typedef long long ll;
typedef long double ld;
using namespace std;
int nt;
int fn_x, fn_y;
int st_x, st_y;
int vt;

ll getDist(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while(nt--) {
    	cin >> fn_x >> fn_y;
    	cin >> st_x >> st_y >> vt;
    	
    	ll dist = getDist(st_x, st_y, fn_x, fn_y);
    	
    	

    	bool ok = false;
    	for (int i = 0; i < 5; i++) {
    		int x, y, speed;
    		cin >> x >> y >> speed;	
    		
    		ll p_dist = getDist(x, y, fn_x, fn_y);
    		if (dist * speed * speed > p_dist * vt * vt) ok = true;
    		else
    		if (dist * speed * speed == p_dist * vt * vt && speed > vt) ok = true;
    	}
    		

    	if (!ok) cout << "YES\n";
    	else
    		cout << "NO\n";
    }
    /**/ return 0;
}
