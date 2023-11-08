#include <iostream>
using namespace std;

class A;

class B{
    public:
        int add(A);
};

class A
{
  private:
    int a, b;
    
  public:
    void setNum(int n1, int n2){
        a = n1;
        b = n2;
    }
    
    void printNum(){
        cout <<"a: " << a << " b: " << b <<endl;
    }
    
    //friend member function
    friend int B::add(A a1);
    //friend class
    //friend class B;
    
};

int B::add(A a1){
    return a1.a+a1.b;
}

int main()
{
    A a1;
    B b1;

    a1.setNum(1,2);
    a1.printNum();
    
    cout << "sum is: " << b1.add(a1);
    return 0;
}
