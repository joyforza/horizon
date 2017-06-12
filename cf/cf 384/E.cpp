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


int shortestSolutionLength(std::vector<std::string> source) {
    int cnt = 0;

    bool dd[2000];
    char sou[2000];
    int m = 0;

    for (int i = 0; i < 2000; i++) dd[i] = false;

    for (int i = 0; i < source.size(); i++) {

        int n = source[i].size();
        bool f[155];
        for (int j = 0; j < n; j++) f[j] = false;

        vector <int> tmp;

        while (true) {
            int pos = -1;
            for (int j = 0; j < n - 1; j++) {
                if (f[j] == false && f[j + 1] == false && source[i][j] == '/' && (source[i][j + 1] == '*' || source[i][j + 1] == '/')) {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) break;

            if (source[i][pos + 1] == '*') {
                int l = pos;
                int r = -1;

                for (int j = n - 1; j > pos; j--)
                if (f[j] == false && f[j - 1] == false && source[i][j] == '/' && source[i][j - 1] == '*') {
                    r = j;
                    break;
                }

                if (r == -1) {
                    f[l] = true;
                    f[l + 1] = true;
                    tmp.pb(l);
                    tmp.pb(l + 1);
                }
                else
                    for (int j = l; j <= r; j++)
                        f[j] = true;
            }
            else
                if (source[i][pos + 1] == '/') {
                    for (int j = pos; j < n; j++)
                        f[j] = true;
                }
        }

            for (int j = 0; j < tmp.size(); j++)
                f[tmp[j]] = false;

            //cout << "new string = \n";
            for (int j = 0; j < n; j++)
            if (f[j] == false && source[i][j] != ' ') {
                sou[++m] = source[i][j];
             //   cout << source[i][j];
            }
            //cout << "\n";
    }



        while (true) {
            int pos = -1;
            for (int j = 0; j < m - 1; j++) {
                if (dd[j] == false && dd[j + 1] == false && sou[j] == '/' && sou[j + 1] == '*') {
                    pos = j;
                    break;
                }
            }

            if (pos == -1) break;

            int l = pos;
            int r = pos;

            for (int j = m - 1; j > pos; j--)
                if (dd[j] == false && dd[j - 1] == false && sou[j] == '/' && sou[j - 1] == '*') {
                    r = j;
                    break;
                }

                for (int j = l; j <= r; j++)
                    dd[j] = true;
        }


        for (int j = 0; j < m; j++) {
            cnt+= (dd[j] == false);
        }

    return cnt;
}


int main() {
   // freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    vector <string> vc;
    vc.pb("var a = 2;");
    vc.pb("/*");
    vc.pb("var b = 2;");
    vc.pb("if (a === b) {");
    vc.pb("  b = a + 1;");
    vc.pb("  //b = a * 2 - 1;");
    vc.pb("}");
    vc.pb("*/");
    vc.pb("var b = 3;");
    vc.pb("return a * b;");

    cout << shortestSolutionLength(vc);

    /**/ return 0;
}
