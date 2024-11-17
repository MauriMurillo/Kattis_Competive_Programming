#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define ll long long

using namespace std;
// Variables
vector< vector<char> > mapa;
int rows, columns;
//Variables
int x[] = {1,-1,0,0};
int y[] = {0,0,1,-1};
void floodfill(pair<int,int> nodo){
    queue <pair<int,int> > Q;
    pair<int,int> padre,hijo;
    mapa[nodo.first][nodo.second] = '#';
    Q.push(nodo);
    while (Q.size()>0)
    {
        padre = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            hijo.first = padre.first + y[i];
            hijo.second = padre.second + x[i];
            if (hijo.first >= 0 and hijo.first < rows and hijo.second >= 0 and hijo.second < columns and mapa[hijo.first][hijo.second] == '-')
            {
                Q.push(hijo);
                mapa[hijo.first][hijo.second] = '#';
            }
        }
    }
}
void solve(){
    int caso =1;
    while (cin>>rows>>columns)
    {
        mapa.assign( rows, vector<char>(columns,'.'));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cin>>mapa[i][j];
            }
        }
        int stars = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                if (mapa[i][j] == '-')
                {
                    floodfill(make_pair(i,j));
                    stars++;
                }
            }
        }
        cout<<"Case "<<caso<<": "<<stars<<endl;
        caso++;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}