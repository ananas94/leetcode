
enum Order {
    ZERO,
    DIGIT,
    EXIT
};

class ZeroEvenOdd {
private:
    int n;
    condition_variable next_one_please;
    mutex mut;
     unsigned int count;
     Order order;
public:
    ZeroEvenOdd(int n) {
        this->n = n;
        this->count = 1;
        this->order = ZERO;
        this->next_one_please.notify_all();
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        while (count <= n) {
            std::unique_lock lk(this->mut);
            this->next_one_please.wait(lk, [this]() { return this->order == ZERO || this->order == EXIT; });
            if (this->order == EXIT) return;
            printNumber(0);
            this->order = DIGIT;
            this->next_one_please.notify_all();
        }
    }

    void even(function<void(int)> printNumber) {
        while (count <= n) {
            std::unique_lock lk(this->mut);
            this->next_one_please.wait(lk, [this]() { return  this->order == DIGIT &&  this->count% 2 == 0 || this->order == EXIT;; });
            if (this->order == EXIT)                return;
            printNumber(count);
            if (this->count == this->n) { this->order = EXIT; this->next_one_please.notify_all(); return; }
            count++;
            this->order = ZERO;
            if (count <= n) this->next_one_please.notify_all();
        }
    }

    void odd(function<void(int)> printNumber) {
        while (count <= n) {
            std::unique_lock lk(this->mut);
            this->next_one_please.wait(lk, [this]() { return this->order == DIGIT && this->count % 2 != 0 || this->order == EXIT; });
            if (this->order == EXIT)                return;
            printNumber(count );
            if (this->count == this->n) { this->order = EXIT; this->next_one_please.notify_all(); return; }
            count++;
            this->order = ZERO;
            this->next_one_please.notify_all();
        }
    }
}; 
