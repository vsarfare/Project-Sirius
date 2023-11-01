
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[] = {3,4,5};
    int b[] = {1,2,4};
    
    int i=0,j=0,k = 0;
    
    int n1 = sizeof(a)/sizeof(a[0]);
    int n2 = sizeof(b)/sizeof(b[0]);
    
    int c[n1+n2];
    
    while(i<n1 && j<n2){
        if(a[i] < b[j]){
            c[k++] = a[i++]; 
        } else {
            c[k++] = b[j++]; 
        }
    }
    
    while(i<n1)
        c[k++] = a[i++];
    
    while(j<n2)
        c[k++] = b[j++]; 
        
    // sort(c, c+n1+n2); 
    
    for (int p = 0; p < n1+n2 ; p++){
        cout<< c[p] << ",";
    }

    return 0;
}
