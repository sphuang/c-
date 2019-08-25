/**
 * Show some util functions of thread library
 * - std::thread::hardware_concurrency()
 * - std::this_thread::get_id()
 * - std::this_thread::sleep_for(<chrono duration>)
 */
#include <thread>
#include <vector>
#include <iostream>
#include <chrono>

int GetCoreNumber() {
    return std::thread::hardware_concurrency();
}

std::thread::id GetThreadID() {
    return std::this_thread::get_id();
}

void ThreadMain(int sleepSeconds) {
    std::cout << "This is " << GetThreadID() << " thread, start execution." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds{sleepSeconds});
    std::cout << "This is " << GetThreadID() << " thread, end execution." << std::endl;
}

int main() {
    std::cout << GetCoreNumber() << std::endl;

    std::vector<std::thread> threads;
    for (int i = 0; i < 2; i++) {
        threads.emplace_back(ThreadMain, i+1);
    }

    for (auto& thread: threads) {
        thread.join();
    }
}