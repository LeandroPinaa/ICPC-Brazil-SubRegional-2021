#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 100005
#define MOD 1000000007
#define int long long
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

typedef struct{
    int num, cor;
}sla;
sla v[NMAX];
int desse[NMAX];

int32_t main(){ faster
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> v[i].num >> v[i].cor;
        desse[v[i].num] = v[i].cor;
    }
    bool flag=true;
    for(int i=1;i<=n;i++){
        if(v[i].cor != desse[i]) flag=false;
    }
    if(flag) cout << "Y\n";
    else cout << "N\n";
}
/*

*/