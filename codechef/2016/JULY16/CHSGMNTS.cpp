#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pp pair<int, int>
#define fi first
#define se second
#define esp 1e-9
#define inf 1000000001
#define mod 1000000007
#define N 1010
typedef long long ll;
typedef long double ld;
using namespace std;
int n;
map<int, int> M;
int a[N];
vector <int> ds[N];
bool f[N];
int nxt[N];
set <int> s;
int cur;

void cntDel(int len) {
    cur -= (len * (len + 1) / 2);
}

void cntAdd(int len) {
    cur += (len * (len + 1) / 2);
}

void cutAt(int x) {
    //cout << "\ntotal set: \n";
    //for (set<int>::iterator it = s.begin(); it != s.end(); it++)
      //  cout << (*it) << " --> " << nxt[*it] << "\n";


    //cout << "dm " << x << endl;

    set<int>::iterator it = s.lower_bound(x);

    int fn = (*it);
    int st = nxt[fn];
   // cout << "cc: " << st << " " << fn << "\n";

    s.erase(it);
    cntDel(fn - st + 1);

    if (st <= x - 1) {
        nxt[x - 1] = st;
        s.insert(x - 1);
        cntAdd(x - st);
    }
    if (x + 1 <= fn) {
        nxt[fn] = x + 1;
        s.insert(fn);
        cntAdd(fn - x);
    }

    //cout << "end " << x << endl;
}

int main() {
    //freopen("in.in", "r", stdin); //freopen("ou.ou", "w", stdout);
    int nt;
    cin >> nt;
    while (nt--) {
        M.clear();
        int cnt = 0;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (M[a[i]] == 0) {
                cnt++;
                M[a[i]] = cnt;
            }
            a[i] = M[a[i]];
        }

        for (int i = 1; i <= cnt; i++) ds[i].clear();
        for (int i = 1; i <= n; i++)
            ds[a[i]].pb(i);
        //cout << "case " << cnt << endl;
        cur = 0;
        ll ret = 0;
        for (int i = 1; i <= n; i++) {
            memset(f, false, sizeof(f));
            s.clear();
            s.insert(n);
            nxt[n] = i;
            cntAdd(n - i + 1);

            nxt[i] = n;
            for (int j = i; j <= n; j++) {
                if (f[j] == false){
                    //cout << j << ": \n";

                    for (int k = 0; k < ds[a[j]].size(); k++)
                    if (ds[a[j]][k] >= i) {
                        f[ds[a[j]][k]] = true;
                        cutAt(ds[a[j]][k]);
                      //  cout << ds[a[j]][k] << " " ;
                    }
                }
                ret += cur;
               // cout << i << " " << j << ": " << cur << endl;
            }
            //cout << i << " " << cur << endl;
        }
        cout << ret << endl;
    }
   /**/ return 0;
}
