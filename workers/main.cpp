// The following code wishes to create a worker thread that runs a
// computation every 300ms - in this case the computation is incrementing
// a counter.
// Unfortunately it seems to exit with a segfault and I have no idea why :(
// Are there any other problems than the segfault?  Any ideas how can they be
// fixed? Many Thanks!!

#include <chrono>
#include <iostream>
#include <memory>
#include <mutex>
#include <thread>

class WorkerTask
{
public:
    void Run()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
        std::lock_guard<std::mutex> guard(counter_mutex_);
        ++endless_counter_;
    }

    static size_t GetCounter()
    {
        std::lock_guard<std::mutex> guard(counter_mutex_);
        return endless_counter_;
    }

private:
    bool shutdown_;
    static std::mutex counter_mutex_;
    static size_t endless_counter_;
};

size_t WorkerTask::endless_counter_ = 0;
std::mutex WorkerTask::counter_mutex_;

class Worker
{
public:
    Worker()
    {
        auto x = std::make_unique<WorkerTask>();
        m_worker_thread_ = std::thread([&]() {
            while (!shutdown_)
                x->Run();
        });
    }

    void RequestShutdown() { shutdown_ = true; }

    ~Worker() { m_worker_thread_.join(); }

private:
    bool shutdown_;
    std::thread m_worker_thread_;
};

int main()
{
    Worker worker1;
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Counter: " << WorkerTask::GetCounter() << "\n";
    return 0;
}
