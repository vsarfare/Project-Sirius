#include <iostream>
using namespace std;

int searchValue(int arr[], int f, int l, int v);

int main()
{
    int arr[] = {};
    int arrSize;
    int first = 0;
    int last = 0;
    int value;
 
    cout << "Enter the array size : " << endl;
    cin >> arrSize;
    
    last = arrSize - 1;
    
    cout << "Enter the array element : " << endl;
    for(int i=0; i < arrSize; ++i) {
        cin >> arr[i];    
    }
    
    cout << "Enter value to search in an array : " << endl;
    cin >> value;
    
    int index = searchValue(arr, first, last, value);
    
    cout << "Value "<< value <<" is at the " << "index " << index << endl;
    
    return 0;       
}

int searchValue(int a[], int f, int l, int v)
{
       do {
       int mid = (f+l)/2;
        
        if(a[mid] == v) {
            return mid;
        } else if(a[mid] < v) {
            return searchValue(a, mid + 1, l, v);
        } else {
            return searchValue(a, f, mid - 1, v);
        }
        
    } while(f <= l);
  
    return -1;
}

