class Event {
    std::condition_variable var;
    std::mutex mut;
    std::atomic<int> notified;
public:
    Event() :notified(0) {}
    void notify() {
        this->notified.store(1, std::memory_order_release);
        this->var.notify_one();
    }
    void wait() {
        std::unique_lock lk(this->mut);
        this->var.wait(lk, [this]() { int test_val = 1; return this->notified.compare_exchange_weak(test_val, 0); });
    }
};

class FooBar {
private:
    int n;
    Event readyToFoo;
    Event readyToBar;
public:
    FooBar(int n) {
        this->n = n;
        this->readyToFoo.notify();
    }

    void foo(std::function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            this->readyToFoo.wait();
            // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            this->readyToBar.notify();
        }
    }

    void bar(std::function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            this->readyToBar.wait();
            // printBar() outputs "bar". Do not change or remove this line.
            printBar();
            this->readyToFoo.notify();
        }
    }
};
