#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 300005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

vector<int>t[NMAX<<2];
int v[NMAX];

void build(int i, int l, int r){
    if(l==r){
        t[i].push_back(v[l]);
        return;
    }
    build(i*2,l,m);
    build(i*2+1,m+1,r);
    merge(t[i*2].begin(),t[i*2].end(),t[i*2+1].begin(),t[i*2+1].end(),back_inserter(t[i]));
}

int range_query(int i, int l, int r, int ql, int qr, int a, int b){
    if(ql<=l&&r<=qr){
        return (int)(upper_bound(t[i].begin(),t[i].end(),b) - lower_bound(t[i].begin(),t[i].end(),a));
    }
    if(ql>r || qr<l) return 0;
    int LChild = 0;
    int RChild = 0;
    if(ql<=m) LChild = range_query(i*2,l,m,ql,qr,a,b);
    if(qr>m) RChild = range_query(i*2+1,m+1,r,ql,qr,a,b);
    return LChild + RChild;
}

int32_t main(){ faster
    int n,q;
    cin >> n >> q;
    for(int i=1;i<=n;i++) cin >> v[i];
    build(1,1,n);
    while(q--){
        int a,p,f;
        cin >> a >> p >> f;
        if(v[a] >= p) cout << "0\n"; //ele aposentou passando
        else cout << range_query(1,1,n,a+1,a+f,p,INF) << '\n';
    }
}