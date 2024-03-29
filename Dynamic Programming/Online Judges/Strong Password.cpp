// Problem link: https://codeforces.com/problemset/problem/1845/C
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define pipii pair<int, pair<int, int>>
#define pipll pair<int, pair<ll, ll>>
#define plpii pair<ll, pair<int, int>>
#define plpll pair<ll, pair<ll, ll>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vpipll vector<pair<int, pair<ll, ll>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const int N = 2e6 + 2;
const int sz = 1e6 + 2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

string s, l, r;
int n, m;
vvi nxt, dp;

// Milaiya milaiya jaite jaite jodi dekhi ami r milaite partesinah tahole true, otherwise mile gele oitar jonno false
int depression(int i, int j){
    if(i > n) return 1;
    if(j == m) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int res = 0;
    for(int k = l[j] - '0'; k <= r[j] - '0'; k++){
        res |= depression(nxt[i][k] + 1, j + 1);
    }
    return dp[i][j] = res;
}

void zahid(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int t; cin >> t;
    while(t--){
        cin >> s;
        cin >> m;
        cin >> l >> r;
        n = s.size();
        nxt.clear(); nxt.resize(n + 1, vi(10, -1));
        dp.clear(); dp.resize(n + 1, vi(10, -1));
        for(int i = n; i >= 0; i--){
            for(int j = 0; j < 10; j++){
                if(i == n){
                    nxt[i][j] = n;
                }
                else{
                    if(j == s[i] - '0') nxt[i][j] = i;
                    else nxt[i][j] = nxt[i + 1][j];
                }
            }
        }
        if(depression(0, 0)) cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
}
