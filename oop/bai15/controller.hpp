#include <iostream>
#include <unordered_map>

typedef void(*callbackFunction)();

class controller
{
private:
    std::unordered_map<std::string, callbackFunction> taskmap;
    std::unordered_map<std::string, std::string> descriptions;
public:
    controller(){};
    ~controller(){};
    void addController(const std::string& keyword, const std::string& description, callbackFunction callback);
    void displayMenu();
    void run();
};


