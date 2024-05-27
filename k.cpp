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

int32_t main(){ faster
    int T,D,M;
    cin >> T >> D >> M;
    int cur = 0;
    int maior_dif = -INF;
    for(int i=0;i<M;i++){
        int x;
        cin >> x;
        int dif = x - cur;
        maior_dif = max(maior_dif,dif);
        cur = x;
    }
    int dif = D - cur;
    maior_dif = max(maior_dif,dif);
    if(maior_dif < T) cout << "N\n";
    else cout << "Y\n";
}