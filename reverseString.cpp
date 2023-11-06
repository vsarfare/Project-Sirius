#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    string originalStr = "the sky is blue", temp;
    string tockenStr;
    
    vector<string> v1;
    
    stringstream ss(originalStr);
    
    while(getline(ss, tockenStr, ' ')){
        v1.push_back(tockenStr);
    }
    
    for(int j=v1.size()-1; j<v1.size() ;j--){
        cout << v1.at(j) << " ";
    }
    
    return 0;
}
