#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    string original;
    string answer;

    cin>>original;
    answer.push_back(original[0]);
    for (int i = 1; i < original.size(); i++)
    {
        if (original[i] != original[i-1])
        {
            answer.push_back(original[i]);
        }
    }
    cout<<answer<<endl;
}