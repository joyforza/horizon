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
#define N 50010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;
int nt, m, a;
ll n;

class matrix {
public:
    int mat[2][2];

    matrix() {
        memset(mat, 0, sizeof(mat));
    }


    matrix mul(matrix a, matrix b) {
        matrix c;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    c.mat[i][j] = (c.mat[i][j] + (ll)a.mat[i][k] * b.mat[k][j] % m) % m;
        return c;
    }

    matrix pow(matrix a, ll mu) {
        if (mu == 1) return a;
        matrix ret = pow(a, mu / 2);
        ret = mul(ret, ret);
        if (mu % 2 != 0)
            ret = mul(ret, a);
        return ret;
    }
};

int main() {
    //freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> nt;
    while (nt--) {
        cin >> a >> n >> m;

        int ret = a % m;

        if (n > 1) {
            /// count digits
            ll mu = 1;
            int tmp = a;
            while (tmp > 0) {
                mu *= 10;
                mu %= m;
                tmp /= 10;
            }

//            cout << mu << "\n";

            /// mul
            matrix c;
            c.mat[0][0] = 1;
            c.mat[0][1] = 1;
            c.mat[1][0] = 0;
            c.mat[1][1] = mu;
            c = c.pow(c, n - 1);

           // cout << c.mat[0][0] << " " << c.mat[0][1] << "\n";
           // cout << c.mat[1][0] << " " << c.mat[1][1] << "\n";

            ret = ((ll)c.mat[0][1] * a % m + (ll)ret * c.mat[1][1] % m) % m;
        }

        cout << ret << "\n";
    }
    /**/ return 0;
}
