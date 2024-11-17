#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
// Variables
int answer;
int nodes, bridges, starts;
vector<vector <int> > ListaAdyacencia;
vector<int> Tumbado;
//Variables
void dfs(int nodo){
    answer++;
    Tumbado[nodo] = 1;
    for (int i = 0; i < ListaAdyacencia[nodo].size(); i++)
    {
        if (Tumbado[ListaAdyacencia[nodo][i]] == 0)
        {
            dfs(ListaAdyacencia[nodo][i]);
        }
    }
}
void solve(){
    int t,a,b;
    cin>>t;
    while (t--)
    {
        answer = 0;
        cin>>nodes>>bridges>>starts;
        ListaAdyacencia.assign(nodes+10, vector<int>());
        Tumbado.assign(nodes+10,0);
        for (int i = 0; i < bridges; i++)
        {
            cin>>a>>b;
            ListaAdyacencia[a].push_back(b);
        }
        for (int i = 0; i < starts; i++)
        {
            cin>>a;
            if (Tumbado[a] == 0)
            {
                dfs(a);
            }
        }
        cout<<answer<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}