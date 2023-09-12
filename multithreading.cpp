#include <iostream>
#include <thread>
#include <unistd.h>

using namespace std;


void task1() {
    for(int i = 1; i <= 10; i++) {
        cout << "Task_1: " << i << endl;
        sleep(1);
    }
}


void task2() {
    for(int i = 0; i < 10; i++) {
        cout << "Task_2: " << (char)('A' + i) << endl;
        sleep(1);
    }
}


int main() {
    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();

    return 0;
}