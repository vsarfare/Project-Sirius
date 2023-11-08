#include <iostream>
#include <vector>
using namespace std;

void getSubArray(vector<int> a,int start ,int end);

void getSubArray(vector<int> a,int start ,int end){
    
    if(end == a.size()){
        return;
    } else if(start > end){
        getSubArray(a, 0, end+1);
    } else {
        for(int i = start; i< end; i++){
            cout << a[i] << ", ";
        }
        cout<< a[end] <<endl;
        getSubArray(a, start+1, end);
    }
    
}


int main()
{
    vector<int> a = {1,2,3};
    
    getSubArray(a,0,0);

    return 0;
}
