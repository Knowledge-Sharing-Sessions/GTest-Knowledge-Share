#ifndef DP_EXAMPLE_CHANCEGAME_H
#define DP_EXAMPLE_CHANCEGAME_H

#include <string>
#include <stdlib.h>
#include <time.h>

class RandomNumberGenerator {
public:
    RandomNumberGenerator() {}
    bool throw_coin() {
        //returns true or false randomly
        throw std::runtime_error("We shouldn't be calling this in a unit test");
    }
    int throw_die(int number_of_sides) {
        //returns a random value between
        //1 and number_of_sides included
        throw std::runtime_error("We shouldn't be calling this in a unit test");
    }
};

class InputReader {
public:
    std::string read_name() const {
        //reads some user input and
        //stores it in the
        //member variable name
        throw std::runtime_error("We shouldn't be calling this in a unit test");
    }
};

template<typename IR = InputReader, typename RNG = RandomNumberGenerator>
class ChanceGame {
public:
    ChanceGame(std::unique_ptr<RNG>&& random_number_generator = std::make_unique<RNG>())
        : name{IR{}.read_name()},
        rng{std::move(random_number_generator)} {}

    int throw_coin_until_heads() {
        int number_of_throws = 0;
        while (rng->throw_coin())
            ++number_of_throws;
        std::cout << name << " threw a coin " << number_of_throws
            << " times before getting heads!\n";
        return number_of_throws;
    }

    int throw_6_sided_dice(int number_of_dice) {
        int total = 0;
        for (int i = 0; i < number_of_dice; ++i)
            total += rng->throw_die(6);
        std::cout << name << " threw " << number_of_dice << " dice and got " << total << "\n!";
        return total;
    }

    std::string get_name() {
        return name;
    }

private:
    std::unique_ptr<RNG> rng{};
    std::string name{};
};

#endif //DP_EXAMPLE_CHANCEGAME_H
