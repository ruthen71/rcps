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

#include "geometry/geometry_template.hpp"

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int A, B;
    cin >> A >> B;
    if (A > B) swap(A, B);
    Double a = A, b = B;
    if (sign(b - 2 / sqrt(3) * a) >= 0) {
        Double ans = 2 / sqrt(3) * a;
        cout << fixed << setprecision(15) << ans << '\n';
    } else {
        Double ok = 15, ng = 30;
        rep(t, 100) {
            Double md = (ok + ng) / 2;
            Double theta = 30 - md;
            Double rada = degree_to_radian(md);
            Double radb = degree_to_radian(theta);
            Double x = a / cos(rada);
            Double y = x * cos(radb);
            if (sign(y - b) <= 0) {
                ok = md;
            } else {
                ng = md;
            }
        }
        {
            Double md = ok;
            Double rada = degree_to_radian(md);
            Double x = a / cos(rada);
            cout << fixed << setprecision(15) << x << '\n';
        }
    }
    return 0;
}
