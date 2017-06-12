#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define ppp pair<pp, int>
#define fi first
#define se second
#define N 200010
#define mod 1000000007
typedef long long ll;
using namespace std;
int n, m;
priority_queue <int> qu[3];
int a[N];
int b[N];
int p[N];
map<int, int> M;

int getPrize(int id) {
    while (!qu[id].empty() && M.count(-qu[id].top())) qu[id].pop();
    if (qu[id].empty()) return -1;
    int val = -qu[id].top();
    M[val] = 1;
    qu[id].pop();
    return val;
}

int main() {
	//freopen("in.in", "r", stdin);
	//freopen("ou.ou", "w", stdsout);
    ios::sync_with_stdio(false);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> p[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) {
        qu[a[i] - 1].push(-p[i]);
        qu[b[i] - 1].push(-p[i]);
    }
    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        cout << getPrize(x - 1) << " ";
    }
    /**/return 0;
}
