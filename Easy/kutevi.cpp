#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Variables
vector<int> DP_PossibleAngles(360,-1);
vector<int> Visited(360,-1);
vector<int> known_angles;
//Variables
bool angle(int angle_to_build){

    angle_to_build += 360;
    angle_to_build = angle_to_build%360;
    if (DP_PossibleAngles[angle_to_build] != -1)
    {
        return DP_PossibleAngles[angle_to_build];
    }

    if (Visited[angle_to_build] != -1)
    {
        return false;
    }
    Visited[angle_to_build] = 1;
    bool addition;
    bool substraction;
    for (int i = 0; i < known_angles.size(); i++)
    {
        addition = angle(angle_to_build + known_angles[i]);
        substraction = angle(angle_to_build - known_angles[i]);
        if (addition or substraction)
        {
            return DP_PossibleAngles[angle_to_build] = 1;
        }
    }

    return DP_PossibleAngles[angle_to_build] = 0;
}
void solve(){
    int N,K,aux;
    cin>>N>>K;
    DP_PossibleAngles[0] = 1;
    while (N--)
    {
        cin>>aux;
        known_angles.push_back(aux);
        DP_PossibleAngles[aux] = 1;
    }
    while (K--)
    {
        cin>>aux;
        if (angle(aux))
        {
            cout<<"YES"<<endl;
        }else
        {
            cout<<"NO"<<endl;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}