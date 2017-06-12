#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 10010
typedef long long ll;
typedef long double ld;
using namespace std;
int nt, L, R, K;
int d[123];
set <vector<int> > ds;

void check(int x) {
    int dem = 0;
    int tmp = x;
    memset(d, 0, sizeof(d));
    vector <int> sub;
    while (tmp > 0) {
        int digit = tmp % 10;
        if (digit > 0)
            if (x % digit == 0)
                d[digit]++;
        tmp /= 10;
    }

    for (int i = 1; i < 10; i++)
        dem += (d[i] > 0);
    if (dem == 3) {
       // cout << x << " " << dem << endl;
       // cout << "list divide: " ;
        for (int i = 1; i < 10; i++)
            if (d[i] > 0) {
                //cout << i << " ";
                sub.pb(i);
            }
        ds.insert(sub);
    }
}

void outList() {
    for (set <vector<int> > :: iterator it = ds.begin(); it != ds.end(); it++) {
        vector <int> cc = (*it);
        for (int j = 0; j < cc.size(); j++)
            cout << cc[j] << " ";
        cout << endl;
    }
}

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
   for (int i = 1; i <= 10000; i++)
        check(i);
    outList();
   /* cin >> nt;
    while (nt--) {
        int cnt = 0;
        cin >> L >> R >> K;
        for (int i = L; i <= R; i++)
            cnt += check(i, K);
        cout << cnt << endl;
    }
   /**/ return 0;
}
