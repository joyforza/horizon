#include <iostream>
#include <algorithm>
#include <cstdio>
#define ll long long
using namespace std;
int  nt;
int n;
string s;

int main() {
    //freopen("in.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin >> nt;
    while(nt--) {
        cin >> n;
        cin >> s;
        bool ok = true;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'H') {
                if (cnt > 0) ok = false;
                cnt++;
            }
            if (s[i] == 'T') {
                if (cnt == 0) ok = false;
                cnt--;
            }
        }
        if (cnt > 0) ok = false;

        if (ok) cout << "Valid\n";
        else
        cout << "Invalid\n";
    }
	return 0;
}
