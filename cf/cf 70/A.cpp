#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<ll, ll>
#define ppp pair<pp, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 200010
#define base 311097
typedef long long ll;
typedef long double ld;
const long long oo = (ll)1e18;
using namespace std;

bool check(char x){
    if (x == 'a') return true;
    if (x == 'e') return true;
    if (x == 'i') return true;
    if (x == 'o') return true;
    if (x == 'u') return true;
    return false;
}

string s;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    int d1 = 0;
    int d2 = 0;
    int d3 = 0;
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        d1 += check(s[i]);
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        d2 += check(s[i]);
    getline(cin, s);
    for (int i = 0; i < s.size(); i++)
        d3 += check(s[i]);
    if (d1 == 5 && d2 == 7 && d3 == 5)
        cout << "YES";
    else
        cout << "NO";
    /**/ return 0;
}
