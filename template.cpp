#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type , less<int> , rb_tree_tag , tree_order_statistics_node_update > pbds ;
//*s.find_by_order(key) -> finds the key(th) element (0 based indexing) 
//s.order_of_key(key)   -> finds the number of elements that are smaller than key

#define ll long long
const int INF = 1e9;        // 1,000,000,000
const long long INFLL = 4e18;
const int N=1e5+10; //for global 1d array



// __int128 binexp(__int128 base, long long exp) {
//     __int128 result = 1;
//     while (exp > 0) {
//         if (exp & 1)
//             result = result * base;
//         base = base * base;
//         exp >>= 1;
//     }
//     return result;
// }
// __int128 binexp_mod(__int128 base, long long exp, __int128 mod) {
//     base %= mod;
//     __int128 result = 1;
//     while (exp > 0) {
//         if (exp & 1)
//             result = (result * base) % mod;
//         base = (base * base) % mod;
//         exp >>= 1;
//     }
//     return result;
// }
// void sieve(ll n)
// {
//     //to get prime numbers 1-n
//     vector<bool> isPrime(n + 1, true);
//     isPrime[0] = isPrime[1] = false;
//     for (int p = 2; p * p <= n; p++) {
//         if (isPrime[p]) {
//             for (int i = p * p; i <= n; i += p)
//                 isPrime[i] = false;
//         }
//     }
//     for (int i = 2; i <= n; i++) {
//         if (isPrime[i])
//             cout << i << " ";
//     }
// }
// vector<ll> sieve_v(ll n) {
//     vector<bool> isPrime(n + 1, true);
//     isPrime[0] = isPrime[1] = false;

//     for (ll p = 2; p * p <= n; p++) {
//         if (isPrime[p]) {
//             for (ll i = p * p; i <= n; i += p)
//                 isPrime[i] = false;
//         }
//     }

//     vector<ll> primes;
//     for (ll i = 2; i <= n; i++) {
//         if (isPrime[i])
//             primes.push_back(i);
//     }

//     return primes;
// }
// bool isPrime(ll n) {
//     if (n <= 1) return false;
//     if (n <= 3) return true;
//     if (n % 2 == 0 || n % 3 == 0) return false;
//     for (ll i = 5; i * i <= n; i = i + 6)
//         if (n % i == 0 || n % (i + 2) == 0)
//             return false;
//     return true;
// }
// __int128 read128() {
//     std::string s;
//     std::cin >> s;
//     bool neg = false;
//     int i = 0;
//     if (!s.empty() && s[0] == '-') {
//         neg = true;
//         i = 1;
//     }
//     __int128 x = 0;
//     for (; i < (int)s.size(); i++) {
//         x = x * 10 + (s[i] - '0');
//     }
//     return neg ? -x : x;
// }
// void print128(__int128 x) {
//     if (x == 0) {
//         std::cout << "0";
//         return;
//     }
//     bool neg = x < 0;
//     if (neg) x = -x;
//     std::string s;
//     while (x > 0) {
//         s.push_back('0' + (int)(x % 10));
//         x /= 10;
//     }
//     if (neg) s.push_back('-');
//     std::reverse(s.begin(), s.end());
//     std::cout << s;
// }

// ---------DSU-------------//

// ll parent[N];
// ll SIZE[N];
// multiset<int> sizes;
// //sizes multiset keeps a track of all size of groups 
// void add(int v){
//     parent[v]=v;
//     SIZE[v]=1;
//     sizes.insert(1);
// }
// int find(int v){
//     if(parent[v]==v)return v;
//     return parent[v]= find(parent[v]);
// }

// //merge function helps to maintain the sizes where all distinct group sizes are stored upon Union 
// void merge(int a,int b){
//     sizes.erase(sizes.find(SIZE[a]));
//     sizes.erase(sizes.find(SIZE[b]));

//     sizes.insert(SIZE[a]+SIZE[b]);
// }

// void Union(int a,int b){
//     a=find(a);
//     b=find(b);
//     if(a==b)return;
//     if(SIZE[b]>SIZE[a]){
//         swap(a,b);
//     }
//     parent[b]=a;
//     merge(a,b);
//     SIZE[a]+=SIZE[b];
// }

//  // **total number of groups = count of all nodes where parent[node]=node** //

// ---------DSU-------------//

// vector<vector<pair<int,int>>>g;
// vector<int>level; //must set level to INF or big value
// void bfs_01(int source){
//     deque<int>q;
//     q.push_back(source);
//     level[source]=0;

//     while(!q.empty()){
//         int cur_v=q.front();
//         q.pop_front();
//         for(auto [child,cost]:g[cur_v]){
//             if(level[cur_v]+cost<level[child]){
//                 level[child]=level[cur_v]+cost;
//                 if(cost==0)q.push_front(child);
//                 else q.push_back(child);
//             }
//         }
//     }
// }

// MST on connected graph/ saturated or densed graph
// ll prims(vector<vector<pair<ll,ll>>>&g,vector<bool>&vis){
//  multiset<pair<ll,ll>>q;
//  q.insert({0LL,1LL});

//  ll sum=0;
//  while(!q.empty()){
//      auto it=q.begin();
//      auto [cost,node]=*it;
//      q.erase(it);
//      if(vis[node])continue;

//      vis[node]=true;
//      sum+=cost;
//      for(auto [wt,child]:g[node]){
//          if(vis[child])continue;
//          q.insert({wt,child});   
//      }
//  }
//  return sum;
// }

// vector<vector<int>>g;
// vector<bool>visited;
// void dfs(int vertex,vector<vector<int>>&g,vector<bool>&visited){
//     //operation after entering the node
//     visited[vertex]=true;

//     for(auto &child:g[vertex]){
//         if(!visited[child]){
//             //operation before entering the child
//             dfs(child,g,visited);
//             //operation after calling dfs on the child
//         }
//     }
//     //operation before exiting the node
// }
// vector<vector<int>>g;
// vector<bool>visited;
// vector<int>level;
// void bfs(int source, vector<vector<int>>& g, vector<int>& level){
//     queue<int> q;
//     q.push(source);
//     level[source] = 0;

//     while(!q.empty()){
//         int cur = q.front(); q.pop();

//         for(auto &child : g[cur]){
//             if(level[child] == -1){
//                 level[child] = level[cur] + 1;
//                 q.push(child);
//             }
//         }
//     }
// }

// vector<vector<pair<ll,ll>>>g;
// void dijkstra(int source){
//     set<pair<ll,ll>>s;
//     s.insert({0,source});
//     ll dist[g.size()]={INFLL};
//     dist[source]=0;
//     while(s.size()){
//         auto [wt,node]=*s.begin();
//         s.erase(s.begin());
//         if(wt>dist[node])continue;
//         for(auto [cost,child]:g[node]){
//             if(cost+wt<dist[child]){
//                 dist[child]=wt+cost;
//                 s.insert({dist[child],child});
//             }
//         }
//     }
// }

void solve(){

}
int main(){ 
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    ll tt=1;
    // cin>>tt;
    for(int i=1;i<=tt;++i){
        // cout<<"Case "<<i<<": ";
        
        solve();
    }
    return 0; 
}
