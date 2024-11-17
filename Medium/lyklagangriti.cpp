#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <deque>
using namespace std;
// Variables
int time_batch;
int batches;
int machines;
int secs;
//Variables
void solve(){
    deque<char> before_cursor;
    deque<char> after_cursos;
    string pass_raw, final_pass ="";
    char aux;
    cin>>pass_raw;
    for (int i = 0; i < pass_raw.size(); i++)
    {
        if (pass_raw[i] == 'B')
        {
            if (!before_cursor.empty())
            {
                before_cursor.pop_back();
            }
        }else if (pass_raw[i] == 'L')
        {
            if (!before_cursor.empty())
            {
                aux = before_cursor.back();
                before_cursor.pop_back();
                after_cursos.push_front(aux);
            }
        }else if (pass_raw[i] == 'R')
        {
            if (!after_cursos.empty())
            {
                aux = after_cursos.front();
                after_cursos.pop_front();
                before_cursor.push_back(aux);
            }
        }else{
            before_cursor.push_back(pass_raw[i]);
        }
    }
    for (int i = 0; i < before_cursor.size(); i++)
    {
        final_pass += before_cursor[i];
    }
    for (int i = 0; i < after_cursos.size(); i++)
    {
        final_pass += after_cursos[i];
    }
    cout<<final_pass<<endl;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}