#include <iostream>
#include <thread>
#include <mutex>
using namespace std;


std::mutex mtx;
int buffer = 0;

void task(const char* threadNumber, int loopRange){
    std::lock_guard<mutex> lock(mtx);
    for (int i = 0; i < loopRange; ++i)
    {
        buffer++;
        std::cout << threadNumber << std::endl;
    }
}

int main(){

    std::thread t1([](){task("T1",10);});
    std::thread t2([](){task("T2",10);});

    t1.join();
    t2.join();

    return 0;
}