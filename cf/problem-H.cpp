#include <bits/stdc++.h>

using namespace std;
using ull = unsigned long long;
using ld = long double;
using ll = long long;
using PII = pair<int, int>;
using PLL = pair<ll, ll>;

#define fast_io \
        ios::sync_with_stdio(false); \
        cin.tie(nullptr);            \
        cout.tie(nullptr);
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define lb(set, x) set.lower_bound(x)
#define ub(set, x) set.upper_bound(x)

const ll INF = 1e12;
const ll MOD = 1e9 + 7;
const int INF_INT = numeric_limits<int>::max();
const ull INF_ULL = numeric_limits<ull>::max();

vector<vector<int>> g;

signed main() {
    fast_io;

    int n, m;
    cin >> n >> m;
    g.resize(n, vector<int> (n, -1));

    for(int h = 0; h < n; ++h) {
        g[h][h] = 0;
    }

    vector<int> col (n, 0);

    for(int h = 0; h < n; ++h) {
        cin >> col[h];
    }

    ll i, j, cen;
    for(int h = 0; h < m; ++h) {
        cin >> i >> j >> cen;
        i--;
        j--;

        g[i][j] = cen;
        g[j][i] = cen;
    }

    vector<vector<ll>> d(n, vector<ll> (n, INF));

    for(int h = 0; h < n; ++h) {
        d[h][h] = 0;
        priority_queue<PLL> q;
        q.push({0, h});
        
        while(!q.empty()) {
            int len = -q.top().first;
            int v = q.top().second;
            q.pop();

            if(len > d[h][v]) continue;
            
            for(int k = 0; k < n; ++k) {
                int to = k;
                int length = g[v][k] * col[h];

                if(d[h][to] > d[h][v] + length && length >= 0) {
                    d[h][to] = d[h][v] + length;
                    q.push({-d[h][to], to});
                }
            }
        }
    }

    ull ans = INF_ULL, buf;

    for(int i = 0; i < n; ++i) {
        buf = 0;
        for(int j = 0; j < n; ++j) {
            buf += 1ULL * d[j][i];
        }
        ans = min(ans, buf);
    }

    cout << ans;

    return 0;
}
