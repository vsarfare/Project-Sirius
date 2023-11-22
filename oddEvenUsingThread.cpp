#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

std::mutex m;
std::condition_variable cv;

int maxCount = 10;
int counter = 0;

void oddEven(string thread, int rem)
{
    while(counter <= maxCount){
        std::unique_lock<mutex> lg(m);
        cv.wait(lg, [rem] { return counter%2==rem;} );
        cout << thread << " : " << counter << endl;
        ++counter;
        cv.notify_one();
    }
}

int main()
{
    std::thread t1(oddEven, "t1", 0);
    std::thread t2(oddEven, "t2", 1);

    t1.join();
    t2.join();
    
    return 0;
}
