#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long long> CD;
int N,M;
long long aux;
int total;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    while (cin>>N>>M and (N != 0 and M != 0))
    {
        CD.clear();
        while (N--)
        {
            cin>>aux;
            CD.push_back(aux);
        }
        while (M--)
        {
            cin>>aux;
            CD.push_back(aux);
        }
        sort(CD.begin(), CD.end());
        total = 0;
        for (int i = 1; i < CD.size(); i++)
        {
            if (CD[i] == CD[i-1])
            {
                total++;
            }
        }
        cout<<total<<"\n";
    }
}