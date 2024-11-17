#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    vector<int> ball(3,0);
    ball[0] = 1;
    ball[1] = 0;
    ball[2] = 0;
    string swaps;
    cin>>swaps;
    for (int i = 0; i < swaps.size(); i++)
    {
        if (swaps[i] == 'A')
        {
            swap(ball[0],ball[1]);
        }else if (swaps[i] == 'B')
        {
            swap(ball[1],ball[2]);
        }else{
            swap(ball[0],ball[2]);
        }
    }
    for (int i = 0; i < 3; i++)
    {
        if (ball[i])
        {
            cout<<i+1<<endl;
        }
    }
}