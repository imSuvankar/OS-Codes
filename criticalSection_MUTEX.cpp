#include <iostream>
#include <thread>
#include <mutex>

using namespace std;


mutex mtx;
int count = 0;

void task() {
    for (int i = 0; i < 1000000; i++) {
        lock_guard<mutex> lock(mtx);
        count++;
    }
}


int main() {
    thread t1(task);
    thread t2(task);

    t1.join();
    t2.join();

    cout << count;
    return 0;
}