/**
 * Show how to launch thread to execute member function
 * - By std::ref(obj)
 * - By pointer
 */
#include <thread>
#include <vector>
#include <iostream>

class MyCar {
public:
    void LaunchThread(int i) {
        total_distant += i;
    }
    void Print() {
        std::cout << "Total distant: " << total_distant << std::endl;
    }
private:
    int total_distant = 0;
};

int main() {
    MyCar myCar;
    std::thread myThread{&MyCar::LaunchThread, &myCar, 1000};

    MyCar myCar2;
    std::thread myThread2{&MyCar::LaunchThread, std::ref(myCar2), 2000};

    myThread.join();
    myThread2.join();

    myCar.Print();
    myCar2.Print();
}