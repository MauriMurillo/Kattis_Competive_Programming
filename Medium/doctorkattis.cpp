#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#define inf first
#define time second.first
#define name second.second
#define ll long long
#define cat pair<int, pair<int,string> >
using namespace std;
// Variables
//Variables

void solve(){
  set< cat > Clinic;
  map < string, cat > Helper;
  int Commands;
  cin>>Commands;
  int timer = 0;
  int option, infection;
  string nameIn;
  while (timer != (-1 * Commands))
  {
    cin>>option;
    cat catNow;
    if (option == 0)
    {
      // cout<<"Add"<<endl;
      cin>>nameIn>>infection;
      catNow = make_pair(infection, make_pair( timer, nameIn));
      Helper[nameIn] = catNow;
      Clinic.insert(catNow);
    }else if (option == 1)
    {
      // cout<<"update"<<endl;
      cin>>nameIn>>infection;
      Clinic.erase(Helper[nameIn]);
      Helper[nameIn].inf += infection;
      Clinic.insert(Helper[nameIn]);
    }else if (option == 2)
    {
      // cout<<"treat"<<endl;
      cin>>nameIn;
      Clinic.erase(Helper[nameIn]);
      Helper.erase(nameIn);
    }else{
      // cout<<"query -> "<<Clinic.size()<<endl;
      if (!Clinic.empty())
      {
        catNow = (*(Clinic.rbegin()));
        cout<<catNow.name<<endl;
      }else{
        cout<<"The clinic is empty"<<endl;
      }
    }
    timer--;
  }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}