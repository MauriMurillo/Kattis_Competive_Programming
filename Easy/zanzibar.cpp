#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// Variables
int test_cases,aux;
vector<int> Records;
//Variables
void solve(){
    cin>>test_cases;
    while (test_cases--)
    {
        Records.clear();
        while(cin>>aux && aux){
            Records.push_back(aux);
        }
        int answer = 0;
        for (int i = 1; i < Records.size(); i++)
        {
            if (Records[i] > (Records[i-1]*2))
            {
                answer += Records[i] - (Records[i-1]*2);
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