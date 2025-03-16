#include "Triangle.h"
template <typename T, size_t N> int SIZE(const T(&t)[N]) { return N; } template<typename T> int SIZE(const T& t) { return t.size(); } string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"'; } string to_string(const char* s) { return to_string((string)s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c) { return string({ c }); } template<size_t N> string to_string(const bitset<N>& b, int x1 = 0, int x2 = 1e9) { string t = ""; for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b) - 1); __iii__ <= __jjj__; ++__iii__) { t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B>& p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A(&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if (l_v_l_v_l == 0) res += '\n'; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2 - x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if (e != l) { if (rnk > 1) { res += '\n'; t_a_b_s = l_v_l_v_l; }; } else { t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if (l_v_l_v_l == 0) res += '\n'; return res; } void dbgm() { ; } template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T) { cout << to_string(H) << " "; dbgm(T...); }
#define debug(...) cout << "" << #__VA_ARGS__ << " : "; dbgm(__VA_ARGS__); cout << endl

using namespace std;

int32_t main() {
    Triangle t({ 0, 0 }, { 5, 0 }, { 0, 5 });
    vector<Point> points = { {3,1},{4,1},{5,9} };

    for (auto& p : points) {
        p.display();
        if (t.isEdging(p))
            cout << "Mmm, I'm on the edge... just a little more, daddy..." << endl;
        else if (t.contains(p))
            cout << "Mmm, yeah... all the way in~" << endl;
        else 
            cout << "No daddy, it's too big to fit" << endl;
        cout << endl;
    }

    points[0].display();
    if (t.otherContains(points[0]))
        cout << "Oh yes, it's in there tight~" << endl;
    else 
        cout << "Nah bro, it’s not getting in" << endl;

    cout << endl;
    if (t.isDegenerate())
        cout << "Flat is justice! Lolis for the win" << endl;
    else
        cout << "I mean, it's a nice triangle and all, but... where's the charm?" << endl;

}
