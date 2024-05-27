#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define NMAX 200005
#define MOD 1000000007
#define pii pair<int,int>
#define INF 1e18
#define faster ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ost tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>
#define m (l+r)/2

vector<int>grafo[NMAX];
queue<int>ordemdfs;
vector<int>queries; //offline
bool morto[NMAX];

void DFS(int x, int p){
    ordemdfs.push(x);
    for(auto viz:grafo[x]){
        if(viz==p) continue;
        DFS(viz,x);
    }
}

int32_t main(){ faster
    int q,nasceu=2;
    cin >> q;
    while(q--){
        int op,x;
        cin >> op >> x;
        if(op==1){
            grafo[x].push_back(nasceu);
            grafo[nasceu].push_back(x);
            nasceu++;
        }
        else queries.push_back(x);
    }
    DFS(1,-1);
    for(auto x:queries){ //percorre os mortos
        morto[x] = true;
        while(morto[ordemdfs.front()]) ordemdfs.pop();
        cout << ordemdfs.front() << '\n';
    } 
}