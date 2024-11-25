#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(a, i, n) for (ll i = (a); i < (n); i++)
#define rrep(i, n) for (ll i = (n - 1); i >= 0; i--)
#define rrep2(a, i, n) for (ll i = (n - 1); i >= a; i--)
#define cinv(v, n)               \
    for (ll i = 0; i < (n); i++) \
        cin >> v[i];
#define coutv(v, n)              \
    for (ll i = 0; i < (n); i++) \
        cout << v[i] << endl;
#define couty() cout << "Yes" << endl;
#define coutn() cout << "No" << endl;
#define decout(a) cout << fixed << setprecision(15) << a << endl;
#define wow() cout << "wow" << endl;
#define coc(a)         \
    cout << a << endl; \
    ;
#define coc2(a, b) cout << a << " " << b << endl;
#define coc3(a, b, c) cout << a << " " << b << " " << c << endl;
#define coc4(a, b, c, d) cout << a << " " << b << " " << c << " " << d << endl;
#define pll pair<ll, ll>
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
void chmin(ll &a, ll b) { a = min(a, b); }
void chmax(ll &a, ll b) { a = max(a, b); }
int main()
{
    ll n;
    ll inf = 999999999999999;
    cin >> n;
    vector<ll> a(n);
    cinv(a, n);
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, inf));
    rep(i, n + 1) dp[i][i] = 0;
    rep2(1, k, n + 1)
    {
        rep(i, n + 1)
        {
            if (i + k > n)
                continue;
            if ((n - k) % 2 == 0)
            {
                dp[i][i + k] = max(dp[i + 1][i + k] + a[i], dp[i][i + k - 1] + a[i + k - 1]);
            }
            else
            {
                dp[i][i + k] = min(dp[i + 1][i + k] - a[i], dp[i][i + k - 1] - a[i + k - 1]);
            }
        }
    }
    cout << dp[0][n] << endl;
}