// Problem link: https://lightoj.com/problem/all-possible-inc-subseq
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
const int N = 2e5 + 5;
const int sz = 1e6 + 2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

int nn;
vll tree;

void update(int i, ll x){
    while(i <= nn){
        tree[i] += x;
        tree[i] %= mod;
        i += (i & -i);
    }
}

void query(int i, ll &sum){
    while(i){
        sum += tree[i];
        sum %= mod;
        i -= (i & -i);
    }
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
    for(int cs = 1; cs <= t; cs++){
        cout << "Case " << cs << ": ";
        int n; cin >> n;
        vll a(n);
        set<ll> s;
        map<ll, ll> idx;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s.insert(a[i]);
        }
        ll curr = 1;
        for(auto it : s){
            idx[it] = curr;
            curr++;
        }
        nn = curr - 1;
        tree.clear();
        tree.resize(nn, 0);
        ll sum = 0;
        for(int i = 0; i < n; i++){
            ll curr_sum = 0;
            query(idx[a[i]] - 1, curr_sum);
            sum += curr_sum + 1;
            sum %= mod;
            update(idx[a[i]], curr_sum + 1);
        }
        cout << sum << '\n';
    }
}
