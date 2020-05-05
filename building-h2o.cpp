class H2O {
    std::condition_variable cvH;
    std::mutex m;
    volatile int count;
    
    std::condition_variable cvO;
    //std::mutex mO;
    //volatile int countO;
public:
    H2O() {
       this->count=0;

    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock lk(m);
        cvH.wait(lk,[this](){return (this->count%3!=0) ; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        this->count++;
        this->cvO.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock lk(m);
        
        cvO.wait(lk, [this]() { return (this->count%3==0); });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        this->count++;
        this->cvH.notify_all();
    }
};