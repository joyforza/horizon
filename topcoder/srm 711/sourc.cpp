#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, int>
#define ppp pair<int, pp>
#define fi first
#define se second
#define esp 1e-15
#define inf 1000000001
#define mod 1000000007
#define N 10010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
ll sum[55];

class ConsecutiveOnes {
public:
    ConsecutiveOnes() {}
    long long get(long long n, int k) {
        for (int i = 0; i < 50; i++)
            sum[i + 1] = sum[i] + (1ll << i);
        ll ret = oo;
        for (int i = 1; i <= 50 - k + 1; i++) {
            ll rr = sum[i + k - 1] - sum[i - 1];
            if (rr >= n) {
                ret = min(ret, rr);
                continue;
            }
            ll need = n - rr;
            rr += min(need, sum[i - 1]);
            need -= min(need, sum[i - 1]);
            ll add = need / (1ll << (i + k - 1));
            if (rr + add * (1ll << (i + k - 1)) < n) add++;
            rr += (add * (1ll << (i + k - 1)));
            ret = min(ret, rr);
        }
        return ret;
    }
};


class OrderedProduct{
public:
    OrderedProduct() {}
    int count(vector <int> a) {

    }
};
int main() {
    //freopen("in.in", "r", stdin);
    //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);


    /**/ return 0;
}

