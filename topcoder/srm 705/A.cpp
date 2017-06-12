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
#define MAXN 505
#define MaxE 1000011
#define sqr(x) (x)*(x)
#define RL double
#define EPS 1e-9
#define ll long long
using namespace std;

vector <int> a[55];
int deg[55];
bool mark[55];

class AlphabetOrderDiv1 {
    public:
    AlphabetOrderDiv1(){}
    string isOrdered(vector <string> words) {
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++)
                for (int k = j + 1; k < words[i].size(); k++)
                    if (words[i][j] != words[i][k]) {
                        a[words[i][k] - 'a'].pb(words[i][j] - 'a');
                        deg[words[i][j] - 'a']++;
                     //   cout << (words[i][k] - 'a') << " --> " << (words[i][j] - 'a') << "\n"; 
                    }
        }
	
		//for (int i = 0; i < 26; i++)
		//cout << deg[i] << " ";
		//cout << "\n";
		
        for (int kk = 0; kk < 26; kk++) {
            int pos = -1;
            for (int i = 0; i < 26; i++)
            if (mark[i] == false) {
                if (deg[i] == 0) {
                    pos = i;
                    break;
                }
            }
          //  cout << "clear node = " << pos << "\n";
            if (pos == -1) return "Impossible";
            mark[pos] = true;
            for (int i = 0; i < a[pos].size(); i++) {
                int v = a[pos][i];
                if (mark[v] == false) {
                    deg[v]--;
                }
            }
        }
        return "Possible";
    }
};

int main() {
   // freopen("in.in", "r", stdin);
   // freopen("ou.ou", "w", stdout);
 //   ios::sync_with_stdio(false);
    cout << "aaa";
    
    /**/ return 0;
}
