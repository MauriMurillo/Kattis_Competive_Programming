#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define fila first
#define col second
int filas,columnas;
char Grid[1010][1010];
int Control[1010][1010];
int incfil[4] = {1,-1,0,0};
int inccol[4] = {0,0,1,-1};
pair<int,int> ini;
pair<int,int> fin;
vector< pair<int,int> > region;
int contador;

bool validate(){
    if (Grid[ini.fila][ini.col] != Grid[fin.fila][fin.col])
    {
        return false;
    }
    return true;
}
void bfs(pair<int,int> nodo, int cond){
    queue< pair<int,int> > Q;
    Q.push(nodo);
    Control[nodo.fila][nodo.col] = contador;
    pair<int,int> padre,hijo;
    while (Q.size() > 0)
    {
        padre = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i++)
        {
            hijo.fila = padre.fila + incfil[i];
            hijo.col = padre.col + inccol[i];
            if (hijo.fila >= 0 && hijo.fila < filas && hijo.col >= 0 && hijo.col < columnas)
            {
                if (Control[hijo.fila][hijo.col] == 0 && Grid[hijo.fila][hijo.col] == char(cond))
                {
                    Control[hijo.fila][hijo.col] = contador;
                    Q.push(hijo);
                }
            }
        }
    }
}
void clearcontrol(){
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            Control[i][j] = 0;
        }
    }
}
void showcontrol(){
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cout<<Control[i][j];
        }
        cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>filas>>columnas;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            cin>>Grid[i][j];
        }
    }
    clearcontrol();
    contador = 1;
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < columnas; j++)
        {
            if (Control[i][j] == 0)
            {
                region.push_back(make_pair(contador,Grid[i][j]));
                bfs(make_pair(i,j),Grid[i][j]);
                contador++;
            }
        }
    }
    //showcontrol();
    int N;
    cin>>N;
    while (N--)
    {
        cin>>ini.fila>>ini.col;
        cin>>fin.fila>>fin.col;
        ini.fila--;
        ini.col--;
        fin.fila--;
        fin.col--;
        if(validate()){
            if (Control[fin.fila][fin.col] == Control[ini.fila][ini.col])
            {
                if(Grid[ini.fila][ini.col] == '1'){
                    cout<<"decimal"<<endl;
                }else{
                    cout<<"binary"<<endl;
                }
            }else{
                cout<<"neither"<<endl;
            }
        }else{
            cout<<"neither"<<endl;
        }
    }
}