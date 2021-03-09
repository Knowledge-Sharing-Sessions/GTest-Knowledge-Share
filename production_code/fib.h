#ifndef DP_EXAMPLE_FIB_H
#define DP_EXAMPLE_FIB_H

#include <limits>
#include <vector>

constexpr long double square_root(long double a, long double error = 4*std::numeric_limits<long double>::epsilon()) {
    auto x = a;
    while(x*x - a > error)
        x = .5 * (x + a/x);
    return x;
}

constexpr long long unsigned nearest_integer(long double x) {
    auto floor = static_cast<long long unsigned>(x);
    return x - floor <= 0.5 ?
        floor :
        floor + 1;
}

constexpr long double power(long double base, unsigned exponent) {
    return exponent == 0 ?
        1 : base * power(base, exponent-1);
}

constexpr long long unsigned recursive_fib(unsigned n) {
    return n < 2 ? n :
           recursive_fib(n-1) + recursive_fib(n-2);
}

class Fib {
public:
    Fib(long long starting_value_0, long long starting_value_1) {
        values.push_back(starting_value_0);
        values.push_back(starting_value_1);
    }
    long long operator()(unsigned n) {
        while (n >= values.size()) {
            auto last = values.size() - 1;
            auto next = values[last] + values[last-1];
            values.push_back(next);
        }
        return values[n];

    }
private:
    std::vector<long long> values{};
};

#endif //DP_EXAMPLE_FIB_H
