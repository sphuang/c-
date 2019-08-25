#include <iostream>
#include <thread>
#include <vector>

void SampleThread(int a) {
    int count = 0;
    for (int i = 0; i < a; i ++) {
        for (int j = 0; j < i ; j++) {
            count++;
        }
    }
    std::cout << "Thread [" << std::this_thread::get_id() << "] has finished" << std::endl; 
}

int main()
{
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; i++) {
        threads.emplace_back(SampleThread, i*1000);
    }

    for (auto& thread: threads) {
        thread.join();
    }

    std::cout << "Main thread has finished" << std::endl;
}