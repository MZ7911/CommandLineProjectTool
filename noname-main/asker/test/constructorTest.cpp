#include <iostream>

#define ASKER_DEBUG

#include "../Asker.h"

int main() {
    Asker asker1;
    std::cout << "asker1 :" << std::endl;
    std::cout << asker1.info() << std::endl;
    Asker asker2(std::string("<"), std::string(">"));
    std::cout << "asker2 :" << std::endl;
    std::cout << asker2.info() << std::endl;
    Asker asker3(std::string(":"), false);
    std::cout << "asker3: " << std::endl;
    std::cout << asker3.info() << std::endl;
    Asker asker4(std::string("<"), std::string(">"), std::string(":"), false);
    std::cout << "asker4: " << std::endl;
    std::cout << asker4.info() << std::endl;
    return 0;
}
