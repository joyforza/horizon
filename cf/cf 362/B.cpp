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

string s;
int a, b;
string dm;

int main() {
//    freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> s;
    a = s[0] - '0';
    int n = s.size();

    int tmp = 1;
    for (int i = n - 1; i >= 0; i--)
        if (s[i] == 'e') {
                n = i;
                break;
        }
        else {
            b += (s[i] - '0') * tmp;
            tmp *= 10;
        }

    dm = (a + '0');
    for (int i = 2; i < b + 2; i++) {
        if (i >= n) dm = dm + '0';
        else
            dm = dm + s[i];
    }



    int m = dm.size();

    int head = 0;
    while (head + 1 < m && dm[head] == '0') head++;

    for (int i = head; i < m; i++)
        cout << dm[i];

    while (n > 0 && s[n - 1] == '0') n--;

    if (b + 2 < n)
        cout << ".";


    for (int i = b + 2; i < n; i++)
        cout << s[i];

   /**/ return 0;
}
