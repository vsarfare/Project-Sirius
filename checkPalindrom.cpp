#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{   
    char str[] = "abba";
    
    int i = 0,j=strlen(str)-1;
    while(i<j){    
        if(str[i++] != str[j--]){
            cout << "Not palindrom";
            return 0;
        }
    }
    cout<< "palindrom";
    
    return 0;
}
