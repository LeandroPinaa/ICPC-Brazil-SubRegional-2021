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
typedef long long ll;

ll arr[200005];

int32_t main(){ faster
    ll b, l, soma_i=0, soma_p=0, aux;
    cin>>b>>l;

    for(int i=1; i<=l; i++) {
        cin>>aux;
        if(i%2 == 0)
            soma_p += aux;
        else
            soma_i += aux;
        arr[i] = aux;
    }
    ll dif = soma_i - soma_p;
    //cout<<soma_i<<" "<<soma_p<<endl;
    
    if(dif % (b+1) == 0) {
        cout<<"0 0\n";
        return 0;
    }
    ll nI, nP;
    if(dif>0) {
        nI = dif%(b+1);
        nP=b+1-nI;
    }
    else {
        nP = abs(dif)%(b+1);
        nI=b+1-nP;
    }
    for(int i=1; i<=l; i++) {
        if(i%2 == 0) {
            //cout<<arr[i]<<" "<<nP<<endl;
            if(arr[i]>=nP) {
                cout<<i<<" "<<(arr[i]-nP)<<endl;
                return 0;
            }
        }
        else {
            //cout<<arr[i]<<" "<<nI<<endl;
            if(arr[i]>=nI) {
                cout<<i<<" "<<(arr[i]-nI)<<endl;
                return 0;
            }
        }
    }
    cout<<"-1 -1\n";
    return 0;
}