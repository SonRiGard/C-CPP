#include "controller.h"

void controller::addController(const std::string& keyword, const std::string& description, callbackFunction callback) {
    taskmap[keyword] = callback;
    descriptions[keyword] = description;
}

void controller::displayMenu() {
    std::cout << "----------------------------------------------------\n";
    std::cout << "LIST COMMAND:\n";
    for (const auto& task : descriptions) {
        std::cout << " - " << task.first << " - " << task.second << "\n";
    }
    std::cout << " EXI - Exit program\n";
}

void controller::run() {
    std::cout << "=== PROGRAM STARTED ===\n";
    bool exit = false;
    while (!exit) {
        displayMenu();
        std::string userChoice;
        std::cout << "\nEnter command: ";
        std::cin >> userChoice;
        std::cin.ignore();
        std::cout << std::endl;

        if (taskmap.find(userChoice) != taskmap.end()) {
            taskmap[userChoice]();  
        } else if (userChoice == "EXIT") {
            exit = true;
            std::cout << "=== PROGRAM END. ===\n";
        } else {
            std::cout << "Invalid Command! Enter again.\n";
        }
    }
}

