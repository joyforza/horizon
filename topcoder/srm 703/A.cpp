#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 100010
#define base 311097
#define M 10000001
typedef long long ll;
typedef long double ld;
using namespace std;

bool f[55];
vector <int> c;
vector <int> one;

class DAGConstruction {
public:
    DAGConstruction(){}
    vector <int> construct(vector <int> x) {
        while (true) {
            bool canFind = false;
            for (int i = 0; i < x.size(); i++)
            if (f[i] == false) {
                if (one.size() >= x[i] - 1) {
                    canFind = true;
                    for (int j = 0; j < x[i] - 1; j++) {
                        c.pb(i);
                        c.pb(one[j]);
                    }
                    f[i] = true;
                    one.pb(i);
                }
            }
            if (!canFind) {
               break;
            }
        }
        for (int i = 0; i < x.size(); i++)
        if (f[i] == false) {
            c.clear();
            c.pb(-1);
        }
        return c;
    }
};
int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);

    /**/ return 0;
}
