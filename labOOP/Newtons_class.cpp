#include "Newtons_class.h"
template <typename T, size_t N> int SIZE(const T(&t)[N]) { return N; } template<typename T> int SIZE(const T& t) { return t.size(); } string to_string(const string s, int x1 = 0, int x2 = 1e9) { return '"' + ((x1 < s.size()) ? s.substr(x1, x2 - x1 + 1) : "") + '"'; } string to_string(const char* s) { return to_string((string)s); } string to_string(const bool b) { return (b ? "true" : "false"); } string to_string(const char c) { return string({ c }); } template<size_t N> string to_string(const bitset<N>& b, int x1 = 0, int x2 = 1e9) { string t = ""; for (int __iii__ = min(x1, SIZE(b)), __jjj__ = min(x2, SIZE(b) - 1); __iii__ <= __jjj__; ++__iii__) { t += b[__iii__] + '0'; } return '"' + t + '"'; } template <typename A, typename... C> string to_string(const A(&v), int x1 = 0, int x2 = 1e9, C... coords); int l_v_l_v_l = 0, t_a_b_s = 0; template <typename A, typename B> string to_string(const pair<A, B>& p) { l_v_l_v_l++; string res = "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; l_v_l_v_l--; return res; } template <typename A, typename... C> string to_string(const A(&v), int x1, int x2, C... coords) { int rnk = rank<A>::value; string tab(t_a_b_s, ' '); string res = ""; bool first = true; if (l_v_l_v_l == 0) res += '\n'; res += tab + "["; x1 = min(x1, SIZE(v)), x2 = min(x2, SIZE(v)); auto l = begin(v); advance(l, x1); auto r = l; advance(r, (x2 - x1) + (x2 < SIZE(v))); for (auto e = l; e != r; e = next(e)) { if (!first) { res += ", "; } first = false; l_v_l_v_l++; if (e != l) { if (rnk > 1) { res += '\n'; t_a_b_s = l_v_l_v_l; }; } else { t_a_b_s = 0; } res += to_string(*e, coords...); l_v_l_v_l--; } res += "]"; if (l_v_l_v_l == 0) res += '\n'; return res; } void dbgm() { ; } template<typename Heads, typename... Tails> void dbgm(Heads H, Tails... T) { cout << to_string(H) << " "; dbgm(T...); }
#define debug(...) cout << "" << #__VA_ARGS__ << " : "; dbgm(__VA_ARGS__); cout << endl

using namespace std;

Newtons_class::Newtons_class() {}
Newtons_class::~Newtons_class() {}

double Newtons_class::F(double x) {
	double tan_x = tan(x);
	return tan_x - (pow(tan_x, 3) + 1) / 3 + 0.2 * pow(tan_x, 5);
}

double Newtons_class::F_(double x) {
	double tan_x = tan(x);
	double sec2_x = (1.0 / cos(x)) * (1.0 / cos(x));
	return sec2_x - 3 * pow(tan_x, 2) * sec2_x + 1.0 * 1.0 * 5 * pow(tan_x, 4) * sec2_x;
}

void Newtons_class::setTolerance(double vol_eps) {
	eps = vol_eps;
}

void Newtons_class::setVolumes(double vol_a, double vol_b) {
	a = vol_a;
	b = vol_b;
}

int Newtons_class::count(double& x) {
    if (F(x) == 0) {
        return 0;
    }

    int max_iter = 1000; 
    int iter = 0;
    int x_ = x;
    while (fabs(F(x)) >= eps && iter < max_iter) {
        x = x - F(x) / F_(x);
        if (fabs(x-x_) <= eps )
        {
            cout << "iter: " << iter << "\n";
            return 1;
        }
        x_ = x;
        iter++;
    }

    cout << "iter: " << iter << "\n";

    if (fabs(F(x)) < eps) {
        return 0;
    }

}
