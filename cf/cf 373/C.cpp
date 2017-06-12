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
#define N 100010
#define base 311097
#define SEG 555
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
int t;
string s;

int main() {
    //freopen("in.in", "r", stdin);// freopen("ou.ou", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> t;
    cin >> s;

    int pos = -1;
    for (int i = 0; i < s.size(); i++)
    if (s[i] == '.') {pos = i; break;}

    bool lead = false;

    for (int i = pos + 1; i < s.size(); i++)
    if (s[i] >= '5') {


    }
    /**/ return 0;
}
