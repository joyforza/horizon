#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#define pp pair<int, int>
#define mp make_pair
#define pb push_back
#define fi first
#define se second
using namespace std;
int n;
bool f[333];
bool dy[333];

vector<pp> ret;
vector<pp> fn;

void duyet(int x) {

    int cnt = 0;
    for (int i = x + 1; i <= n; i++)
        for (int j = 0; j <= n; j++)
            if (i + j > n) break;
            else
                if (dy[j] == false && f[n - i - j] == false) {
                    cnt++;
                    f[n - i - j] = true;
                    dy[j] = true;
                    ret.pb(mp(i, j));
                    duyet(i);
                    f[n - i - j] = false;
                    dy[j] = false;
                    ret.pop_back();
            }

    if (cnt == 0) {
        if (fn.size() < ret.size()) {
            fn.clear();
            for (int i = 0; i < ret.size(); i++)
                fn.pb(ret[i]);
        }
    }
}

int main() {
    cin >> n;
    duyet(-1);
    cout << fn.size() << "\n";
    for (int i = 0; i < fn.size(); i++)
        cout << fn[i].fi << " " << fn[i].se << " " << n - (fn[i].fi + fn[i].se) << endl;
    return 0;
}
