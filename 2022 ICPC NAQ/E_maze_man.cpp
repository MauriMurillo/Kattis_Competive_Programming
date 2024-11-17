#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int M[110][110];
int n, m;
vector< string > mapa(110, "");
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};
long long floodfill(pair<int, int> nodo, int entrance)
{
    int dotcPicked = 0;
    queue<pair<int, int> > Q;
    pair<int, int> padre, hijo;
    M[nodo.first][nodo.second] = 1;
    Q.push(nodo);
    while (Q.size() > 0)
    {
        padre = Q.front();
        Q.pop();
        // cout<<"padre: "<<padre.first<<" : "<<padre.second<<endl;
        for (int i = 0; i < 4; i++)
        {
            hijo.first = padre.first + y[i];
            hijo.second = padre.second + x[i];
            if (hijo.first >= 0 and hijo.first < n and hijo.second >= 0 and hijo.second < m and M[hijo.first][hijo.second] == -1)
            {
                if (mapa[hijo.first][hijo.second] == ' ' )
                {
                    Q.push(hijo);
                    M[hijo.first][hijo.second] = 1;
                    mapa[hijo.first][hijo.second] = char(entrance);
                }else if (mapa[hijo.first][hijo.second] == '.')
                {
                    Q.push(hijo);
                    M[hijo.first][hijo.second] = 1;
                    mapa[hijo.first][hijo.second] = char(entrance);
                    dotcPicked++;
                }
                // cout<<"hijo: "<<hijo.first<<" : "<<hijo.second<<endl;
            }
        }
    }
    return dotcPicked;
}
void showGrid(){
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cout << mapa[y][x] <<" ";
        }
        cout<<endl;
    }
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            cout << M[y][x] <<" ";
        }
        cout<<endl;
    }
}
int main()
{
    cin >> n >> m;
    cin.ignore();
    for (int y = 0; y < n; y++)
    {
        getline(cin,mapa[y]);
        for (int x = 0; x < m; x++)
        {
            M[y][x] = -1;
        }
    }
    int minimun_players = 0;
    int entranceCount = 0;
    int dotsLeft = 0;
    //65 A 87 X
    for (int y = 0; y <= n; y++)
    {
        for (int x = 0; x <= m; x++)
        {
            if (M[y][x] == -1 and int(mapa[y][x]) >= 65 and int(mapa[y][x]) <= 87)
            {
                // cout<<y<<" : "<<x<<endl;
                // cout<<mapa[y][x]<<endl;
                long long useful = floodfill(make_pair(y, x),mapa[y][x]);
                if (useful > 0)
                {
                    entranceCount++;
                }
            }
        }
    }

    // showGrid();
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < m; x++)
        {
            if(mapa[y][x] == '.'){
                dotsLeft++;
            }
        }
        cout<<endl;
    }
    cout<<entranceCount<<" "<<dotsLeft<<endl;
    // cout << resultado << endl;
}
