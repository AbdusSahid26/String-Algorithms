/*

     _____________    _____________    _____________	          _____________    _____________
    (  ___________)  |  _________  )  (___________  )	         (___________  )  (  ___________)
    ( (		     | |         | )	          | )            	     ) )  ( (
    ( (___________   | |_________| )   ___________| )	          ___________) )  ( (___________
    (___________  )  |  ___________)  |  _________  )            (  ___________)  (  _________  )
                ) )  | |	      | |         | )  	         ( (              ( (         ) )
     ___________) )  | |___________   | |_________| )   ______   ( (___________   ( (_________) )
    (_____________)  |_____________)  |_____________)  (______)  (_____________)  (_____________)



    Name  : Abdus Sahid
    Don't give up until the last second.

    Topcoder handle : sea_26
    Codechef handle : sea_26

    Practice makes a man perfect.

*/

#pragma GCC optimize("03")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;


template <typename T>
      using ordered_set = tree<T, null_type, less<T>,
          rb_tree_tag, tree_order_statistics_node_update>;


using ll = long long;
using ld = long double;

typedef pair<int, int> PII;
typedef pair<ll, int> PLI;
typedef pair<int, ll> PIL;
typedef pair<ll, ll> PLL;

typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<int> VI;
typedef vector<double> VD;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef vector<ll> VL;
typedef vector<VL> VVL;

typedef map<int, int> MII;
typedef map<ll, ll> MLL;
typedef map<PII, int> MPIII;
typedef map<string, int> MSI;

typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef unordered_map<ll,ll> UOML;

typedef multiset<PLI> MSPLI;
typedef priority_queue<int> PQI;

const int M = 1e9 + 7;
const ll FM = 998244353;
const ld eps = 1e-9;
const ld PI = acos(-1.0);
VL PN = {2,3,5,7,11,13,17,19,23};
// const double pi = atan2(0, -1);
// const double PI = 4 * atan(1);
// const double pi = 2*cos(0.0);

const int iinf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

#define mp make_pair
#define eb emplace_back
#define pf push_front
#define pb push_back
#define ppb pop_back()
#define ep emplace
#define fbo(ind) find_by_order(ind);
#define ook(val) order_of_key(val);
#define f first
#define s second
#define sz size()

#define bp(n) __builtin_popcount(n)
#define bclz(n) __builtin_clzll(n)
#define bctz(n) __builtin_ctzll(n)
#define bip(n) __builtin_parity(n)

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rvs(v) sort(all(v),greater<int>())
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))
#define acm(v, ini) accumulate(all(v),ini)
#define uni(v) vsort(v),(v).erase(unique(all(v)), (v).end())
#define smp(container, element) (container.find(element) != container.end())
#define vp(container, element) (find(all(container),element) != container.end())

#define ub(v,k) upper_bound(all(v), k) - v.begin()
#define lb(v,k) lower_bound(all(v), k) - v.begin()
#define msz(a) memset(a, 0, sizeof(a))
#define msm(a) memset(a, 0xff, sizeof(a))
#define fpre(n) fixed << setprecision(n)
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define sea template< typename T
#define tc int tt; cin >> tt; for(int t=1; t<=tt; t++)

#define rep(i,n) for(__typeof(n) i=0; i<n; i++)
#define per(i,n) for(__typeof(n) i=n-1; i>=0; i--)
#define lrep(i,p,q) for(__typeof(q) i=p; i<=q; i++)
#define perl(i,p,q) for(__typeof(p) i=p; i>=q; i--)
#define IT(it,x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define RIT(it,x) for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); it++)

sea > inline bool checkbit(T n, T pos) {return n & (1 << pos);}
sea > inline int setbit(T n, T pos) {return n | (1 << pos);}
sea > inline int resetbit(T n, T pos ) {return n & ~(1 << pos);}
sea > inline int flipbit(T n, T pos) {return n ^ (1 << pos);}

sea > inline T MAX(T a, T b){ return a ^ ((a ^ b) & -(a < b)); }
sea > inline T MIN(T a, T b){ return b ^ ((a ^ b) & -(a < b)); }
sea > void SWAP(T &a, T &b){ a = ((a) ^= (b)),  b = ((b) ^= (a)),  a = ((a) ^= (b)); }
sea > inline T sqr(T x){ return (x) * (x); }
sea > inline bool isPoT(T x){ return (x != 0 && (x&(x - 1)) == 0); }

sea > bool chkmax(T &a, const T b){ if(a < b){a = b; return true;} else return false; }
sea > bool chkmin(T &a, const T b){ if(a > b){a = b; return true;} else return false; }

sea > inline T gcd(T a, T b){ while (b) b ^= a ^= b ^= a %= b; return a; }
sea > T exgcd(T a, T b, T& x, T& y){ if(!b){ x = 1; y = 0;return a;} else{ T g = exgcd(b,a%b,y,x); y -= (a/b)*x; return g;}}
sea > inline T lcm(T a, T b){ return (a / gcd(a,b)) * b; }

sea > inline T mod(T a, T b){ return a >= b ? a % b : a; }
sea > T binpow(T n, T p){ T res = 1; while(p > 0){ if(p & 1) res *= n; n *= n; p >>= 1; } return res;}   /// n^p
sea > T bigmod(T n, T p, T M){ n %= M; T res = 1; while(p > 0){ if(p & 1)res = ((res%M)*(n%M))%M; n = ((n%M)*(n%M))%M; p >>= 1; } return res;}  /// (n^p) % M
sea > T modInv(T a, T m){return bigmod(a, m-2, m);}
sea > T mulmod(T a, T b, T M){ T x = 0, y = a % M; while(b > 0){ if(b&1) x = (x + y) % M; } y = (y << 1) % M; b >>= 1; }  /// (a*b) % M
bool mrpt(const ll n){ if(n<2) return false; if(n%2==0) return n==2; ll s = 0, d = n-1; while(d&1) s++, d/=2;for(auto a: PN){
        if(a > n-2) break; ll x = bigmod(a,d,n); if(x == 1 || x == n-1) continue;
        rep(i,s-1){ x = mulmod(x,x,n); if(x==1) return false; if(x==n-1) goto next_it; } return false; next_it:; }
return true;
}
sea > inline T BinCof(T n, T k){ T res = 1; if(k > n-k) k = n-k; for(T i=0 ;i<k ;i++){ res *= (n-i); res /= (i+1);} return res; }

static inline bool is_digit(char c){ return static_cast<unsigned char>(c - '0') < 10; }
static inline bool is_upper(char c){ return static_cast<unsigned char>(c - 'A') < 26; }
static inline bool is_lower(char c){ return static_cast<unsigned char>(c - 'a') < 26; }

namespace input{
    sea > inline void read(T& x){
        bool Negative = false; register int c; x = 0; c = getchar();
        if(c == '-'){ Negative = true; c = getchar(); }
        for(; (c>47 && c<58); c = getchar()) x = (x << 3) + (x << 1) + c -48; if(Negative) x *= -1;
    }
    sea, class... Ts> void read(T& t, Ts&... ts){ read(t); read(ts...); }
    sea > istream &operator>>(istream &is, vector<T> &vec){ for(auto &v : vec) is >> v; return is; }
}
using namespace input;


void get_data(void){
    //read();
}

VI RabinKarp(string const& s, string const& t){

    const int p = 31;
    const int m = 1e9 + 9;
    int lnS = s.sz;
    int lnT = t.sz;

    VL p_pow(MAX(lnS, lnT));
    p_pow[0] = 1;
    lrep(i,1,(int)p_pow.sz - 1) p_pow[i] = (p_pow[i-1] * p) % M;

    VL h(lnT+1, 0);
    rep(i, lnT) h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % M;

    ll h_s = 0;
    rep(i, lnS) h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % M;

    VI occurs;
    for(int i = 0; i+lnS-1 < lnT; i++)
        if((h[i+lnS] + M - h[i])% M == h_s * p_pow[i] % M) occurs.eb(i);

    return occurs;
}


class PatternMatching{
public:
    void solve(istream& cin, ostream& cout){
        get_data();

        string text, pattern;
        cin >> text >> pattern;

        VI vec = RabinKarp(pattern, text);
        int ln = vec.sz;
        cout << "Total occurrences : " << ln << endl;
        cout << "Matching position : ";
        rep(i, ln) cout << vec[i] << " \n"[i == ln - 1];
        cout << endl;
    }
};


signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef LOCAL_DEFINE
        auto start_time = clock();
    #endif // LOCAL_DEFINE

    #ifdef LOCAL_DEFINE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // LOCAL_DEFINE

    PatternMatching Problem;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    Problem.solve(in, out);

    #ifdef LOCAL_DEFINE
        auto end_time = clock();
        cerr << "Time Elapsed: " << fpre(3) << 1.0 * (end_time - start_time) / CLOCKS_PER_SEC  << " Sec"<< endl;
    #endif // LOCAL_DEFINE

    return 0;
}

