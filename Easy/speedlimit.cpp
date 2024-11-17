#include <iostream>
#include <vector>
using namespace std;
vector<int> miles;
vector<int> times;

int main(){
    int N;
    int totalmiles;
    int mile,time,prevtime = 0;
    while (cin>>N and N != -1)
    {
        prevtime = 0;
        miles.clear();
        times.clear();
        while (N--)
        {
            cin>>mile>>time;
            time = time - prevtime;
            prevtime+=time;
            miles.push_back(mile);
            times.push_back(time);
            totalmiles = 0;
            for (int i = 0; i < miles.size(); i++)
            {
                totalmiles += miles[i] * times[i];
            }
        }
        cout<<totalmiles<<" miles"<<endl;
    }
}