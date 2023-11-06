#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    string originalStr = "the sky is blue";
    string tockenStr;
    
    vector<string> v1;
    
    stringstream ss(originalStr);
    
    while(getline(ss, tockenStr, ' ')){
        v1.push_back(tockenStr);
    }
    
    int i = 0;
    string last;
    
    for(i=0; i<3; i++){
        last = v1.at(0);
        for(int j=0; j < v1.size()-1; j++){
            v1.at(j) = v1.at(j+1);
        }
         v1.at(v1.size()-1) = last;
    }
    
    vector<string>::iterator it;
    for(it=v1.begin(); it!= v1.end(); it++){
        cout << *it << endl;
    }
    
    return 0;
}
