// TaskQueue.hpp
#pragma once
#ifndef TASK_QUEUE_HPP
#define TASK_QUEUE_HPP

#include <queue>
#include <memory>
#include <mutex>
#include <condition_variable>
#include <chrono>

template<typename T>
class TaskQueue {
public:
    void enqueue(std::shared_ptr<T> task);
    std::shared_ptr<T> dequeueWithTimeout(int timeoutMs);
    bool isEmpty() const;

private:
    mutable std::mutex mtx_;
    std::condition_variable cv_;
    std::queue<std::shared_ptr<T>> queue_;
};

// 模板实现必须放在头文件中
template<typename T>
void TaskQueue<T>::enqueue(std::shared_ptr<T> task) {
    std::lock_guard<std::mutex> lock(mtx_);
    queue_.push(task);
    cv_.notify_one();
}

template<typename T>
std::shared_ptr<T> TaskQueue<T>::dequeueWithTimeout(int timeoutMs) {
    std::unique_lock<std::mutex> lock(mtx_);
    if (!cv_.wait_for(lock, std::chrono::milliseconds(timeoutMs), [this] { return !queue_.empty(); })) {
        return nullptr;
    }
    auto task = queue_.front();
    queue_.pop();
    return task;
}

template<typename T>
bool TaskQueue<T>::isEmpty() const {
    std::lock_guard<std::mutex> lock(mtx_);
    return queue_.empty();
}

#endif // TASK_QUEUE_HPP