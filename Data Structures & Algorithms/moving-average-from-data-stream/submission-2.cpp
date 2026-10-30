class MovingAverage {
private:
    long long sum = 0;
    int count = 0;
    int index = 0;
    int size;
    std::vector<int> vect;

public:
    MovingAverage(int size) : size(size), vect(size, 0) {}

    double next(int val) {
        sum -= vect[index];
        vect[index] = val;
        sum += val;

        index = (index + 1) % size;

        if (count < size) {
            count++;
        }

        return static_cast<double>(sum) / count;
    }
};