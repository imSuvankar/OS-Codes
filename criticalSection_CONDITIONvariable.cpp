#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;


int count = 0;
mutex mtx;
condition_variable cv;


void task() {
    for (int i = 0; i < 1000000; i++) {
        {
            lock_guard<mutex> lock(mtx);
            count++;
        }
        cv.notify_all();
    }
}


int main() {
    thread t1(task);
    thread t2(task);

    t1.join();
    t2.join();

    cout << count << endl;
    return 0;
}
