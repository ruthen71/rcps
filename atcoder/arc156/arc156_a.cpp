#include <bits/stdc++.h>
using namespace std;

#ifdef _RUTHEN
#include <debug.hpp>
#else
#define show(...) true
#endif

using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
template <class T> using V = vector<T>;

void solve() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int cnt = count(S.begin(), S.end(), '1');
    if (cnt % 2) {
        cout << -1 << '\n';
    } else {
        if (cnt >= 4 or cnt == 0) {
            cout << cnt / 2 << '\n';
        } else {
            // cnt = 2
            V<int> ind;
            rep(i, N) if (S[i] == '1') ind.push_back(i);
            if (ind[0] + 1 == ind[1]) {
                if (N == 3) {
                    cout << -1 << '\n';
                } else if (N == 4) {
                    if (ind[0] == 1) {
                        cout << 3 << '\n';
                    } else {
                        cout << 2 << '\n';
                    }
                } else {
                    cout << cnt / 2 + 1 << '\n';
                }
            } else {
                cout << cnt / 2 << '\n';
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) solve();
    return 0;
}
