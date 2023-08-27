#include<bits/stdc++.h>

using namespace std;

void PrintStack(stack<int> s)
{
    
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    PrintStack(s);
    cout << x << " ";
    s.push(x);
}

int main(){

}