#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int a,b,c;
    vector<int> aux(3,0);
    cin>>aux[0]>>aux[1]>>aux[2];
    sort(aux.begin(), aux.end());
    string answer = "";
    for (int i = 0; i < 3; i++)
    {
        char car;
        cin>>car;
        if (car == 'A')
        {
            answer += to_string(aux[0]);
        }
        if (car == 'B')
        {
            answer += to_string(aux[1]);
        }
        if (car == 'C')
        {
            answer += to_string(aux[2]);
        }
        answer+=" ";
    }
    answer.pop_back();
    cout<<answer<<endl;
}