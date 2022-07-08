// Multithread vs Multitasking
// Multitasking: Switch between multiple task in a very short time
// Multithread: Two part of the job can be executed at the same time. e.g. two cores

#include <iostream>
#include <thread>

void func1() {
    for (size_t i = 0; i < 5000; i++) {
        std::cout << '+';
    }
    std::cout << ">>>>>>>>>>>" << std::endl; 
}

void func2() {
    for (size_t i = 0; i < 5000; i++) {
        std::cout << '-';
    }
    std::cout << ">>>>>>>>>>>" << std::endl; 
}

int main() {

    std::thread worker1(func1);
    std::thread worker2(func2);
    bool res_thread_1 = worker1.joinable();
    if (res_thread_1)
    {
        worker1.join();
    }
    bool res_thread_2 = worker2.joinable();
    if (res_thread_2) {
        worker2.join();
    }
    return 0;
}