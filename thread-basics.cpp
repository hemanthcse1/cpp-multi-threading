#include<iostream>
#include<thread>
#include<chrono>

void sleepThread(){
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Wake up.." << std::endl;
}

void printThreadId(){
    std::cout << "Thread name: "<< std::this_thread::get_id() << std::endl;
    std::cout << "sleep thread for 5 seconds" << std::endl;
    sleepThread();
}

int main(){

    std::cout << "Hello multithreading....."<< std::endl;

    printThreadId();
    return 0;
}