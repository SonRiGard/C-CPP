// Chuong trinh so sanh toc do xu li 1 bien INT trong xu li da luon thread-safe voi atomic va mutex.
#include <iostream>
#include <atomic>
#include <mutex>
#include <thread>
#include <vector>
#include <chrono>

const int NUM_THREADS = 8;  // Số luồng thử nghiệm
const int NUM_ITERATIONS = 1'000'000;  // Số lần tăng giá trị

std::atomic<int> atomic_counter(0);
int mutex_counter = 0;
std::mutex mtx;

void increment_atomic() {
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        atomic_counter.fetch_add(1, std::memory_order_relaxed);
    }
}

void increment_mutex() {
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++mutex_counter;
    }
}

int main() {
    std::vector<std::thread> threads;

    // Benchmark std::atomic<int>
    auto start_atomic = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(increment_atomic);
    }
    for (auto& t : threads) t.join();
    auto end_atomic = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_atomic = end_atomic - start_atomic;

    std::cout << "Atomic Counter: " << atomic_counter.load() << "\n";
    std::cout << "Time (std::atomic<int>): " << elapsed_atomic.count() << " seconds\n";

    // Reset variables
    threads.clear();
    atomic_counter = 0;
    mutex_counter = 0;

    // Benchmark std::mutex
    auto start_mutex = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(increment_mutex);
    }
    for (auto& t : threads) t.join();
    auto end_mutex = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_mutex = end_mutex - start_mutex;

    std::cout << "Mutex Counter: " << mutex_counter << "\n";
    std::cout << "Time (std::mutex): " << elapsed_mutex.count() << " seconds\n";

    return 0;
}