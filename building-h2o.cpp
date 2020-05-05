class H2O {
    std::condition_variable cvH;
    std::mutex mH;
    atomic<int> countH;
    
    std::condition_variable cvO;
    std::mutex mO;
    atomic<int> countO;
public:
    H2O() {
       this->countH=0;
       this->countO=0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        std::unique_lock lk(mH);
        cvH.wait(lk,[this](){return (this->countO*2) > (this->countH) ; });
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        this->countH++;
        this->cvO.notify_one();
    }

    void oxygen(function<void()> releaseOxygen) {
        std::unique_lock lk(mO);
        
        cvO.wait(lk, [this]() { return (this->countH) == (2*this->countO); });
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        this->countO++;
        this->cvH.notify_one();
        this->cvH.notify_one();
    }
};