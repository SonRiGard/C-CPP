#include <iostream>
#include <vector>
#include <mutex>
#include <thread>
#include <chrono>

const int NUM_THREADS = 8;  // Số luồng thử nghiệm
const int NUM_ITERATIONS = 100000;  // Số lần push_back()

std::vector<int> data_mutex;  
std::mutex mtx;

void push_back_mutex() {
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        data_mutex.push_back(i);
    }
}

void push_back_no_mutex(std::vector<int>& data) {
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        data.push_back(i);  // Không thread-safe
    }
}

int main() {
    std::vector<std::thread> threads;

    // Benchmark với std::mutex
    auto start_mutex = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(push_back_mutex);
    }
    for (auto& t : threads) t.join();
    auto end_mutex = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_mutex = end_mutex - start_mutex;

    std::cout << "Size with mutex: " << data_mutex.size() << "\n";
    std::cout << "Time (std::mutex): " << elapsed_mutex.count() << " seconds\n";

    // Reset
    threads.clear();
    std::vector<int> data_no_mutex;

    // Benchmark không dùng mutex (có thể crash)
    auto start_no_mutex = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(push_back_no_mutex, std::ref(data_no_mutex));
    }
    for (auto& t : threads) t.join();
    auto end_no_mutex = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_no_mutex = end_no_mutex - start_no_mutex;

    std::cout << "Size without mutex: " << data_no_mutex.size() << " (Có thể sai do race condition!)\n";
    std::cout << "Time (no mutex - unsafe): " << elapsed_no_mutex.count() << " seconds\n";

    return 0;
}
