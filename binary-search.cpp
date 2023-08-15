#include <iostream>
using namespace std;

int main()
{
    int arr[] = {};
    int arrSize;
    int first = 0;
    int last = 0;
    int mid ;
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
    
    do { 
        mid = (first+last)/2;
        
        if(arr[mid] == value) {
            cout << "Value "<< value <<" is at the " << "index " << mid << endl;
            break;
        } else if(arr[mid] < value) {
            first = mid + 1; 
        } else {
            last = mid - 1;
        }
        
    } while(first <= last);

    return 0;       
}
