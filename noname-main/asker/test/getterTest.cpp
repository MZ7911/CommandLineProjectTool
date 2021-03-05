#include <iostream>

#define ASKER_DEBUG

#include "../Asker.h"

int main() {
    Asker asker(std::string("<"), std::string(">"), std::string(":"), false);
    std::cout << "getLeftBrace() : \"" << asker.getLeftBrace() << "\"" << std::endl;
    std::cout << "getRightBrace() : \"" << asker.getRightBrace() << "\"" << std::endl;
    std::cout << "getPrompt() : \"" << asker.getPrompt() << "\"" << std::endl;
    std::cout << "getPromptInBrace() : \"" << asker.getPromptInBrace() << "\"" << std::endl;
    std::cout << "getMessage() : \"" << asker.getMessage("Test") << "\"" << std::endl;
    return 0;
}