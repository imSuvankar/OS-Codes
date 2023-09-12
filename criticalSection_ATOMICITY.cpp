// this will always give 2000000 output
// ATOMICITY -> atomic Count variable


#include <iostream>
#include <thread>
#include <atomic>

using namespace std;


atomic<int> count(0);

void task() {
    for (int i = 0; i < 1000000; i++) count++;
}

int main() {
    thread t1(task);
    thread t2(task);

    t1.join();
    t2.join();

    cout << count;
    return 0;
}