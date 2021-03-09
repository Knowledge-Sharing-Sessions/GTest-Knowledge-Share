#ifndef DP_EXAMPLE_DATABASEREADER_H
#define DP_EXAMPLE_DATABASEREADER_H

#include <string>

class DatabaseReader {
public:
    virtual int getAgeFromId(int id) {
        //pretend this is
        //beautiful code
        //that reads a value
        //from a database
        throw std::runtime_error("We shouldn't be calling this in a unit test");
    }
    virtual std::string getNameFromId(int id) {
        //pretend this is
        //beautiful code
        //that reads a value
        //from a database
        throw std::runtime_error("We shouldn't be calling this in a unit test");
    }
};

//function we want to test
inline std::string hello(int id,
        std::shared_ptr<DatabaseReader> dbReader = std::make_shared<DatabaseReader>()
                ) {
    std::string name = dbReader->getNameFromId(id);
    int age = dbReader->getAgeFromId(id);
    std::stringstream hello;
    hello << "hello, " << name << ". you are "
            << age << " years old!";
    return hello.str();
};

#endif //DP_EXAMPLE_DATABASEREADER_H
