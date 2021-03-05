#ifndef ASKER_H
#define ASKER_H


#include <string>


class Asker {
    
public:
    
    Asker() :
        leftBrace("$"), rightBrace("$"), prompt("?"), promptInBrace(true) {

    }

    Asker(std::string leftBrace, std::string rightBrace) :
        leftBrace(leftBrace), rightBrace(rightBrace), prompt("?"), promptInBrace(true) {

    }

    Asker(std::string prompt, bool promptInBrace) :
        leftBrace("$"), rightBrace("$"),prompt(prompt), promptInBrace(promptInBrace) {

    }

    Asker(std::string leftBrace, std::string rightBrace, std::string prompt, bool promptInBrace) :
        leftBrace(leftBrace), rightBrace(rightBrace), prompt(prompt), promptInBrace(promptInBrace) {

    }

    std::string getLeftBrace() const {
        return leftBrace;
    }

    std::string getRightBrace() const {
        return rightBrace;
    }

    std::string getPrompt() const {
        return prompt;
    }

    bool getPromptInBrace() const {
        return promptInBrace;
    }

    std::string getMessage(std::string object) const {
        std::string message = leftBrace + object;
        if (promptInBrace) {
            message += prompt + rightBrace;
        } else {
            message += rightBrace + prompt;
        }
        return message;
    }
    
private:
    
    std::string leftBrace;
    std::string rightBrace;
    
    std::string prompt;
    bool promptInBrace;

#ifdef ASKER_DEBUG

public:

    std::string info() const {
        std::string info =
                std::string("+-------------------------+-------------+-------\n") +
                "| Private Member Variable | Type        | Value \n" +
                "+-------------------------+-------------+-------\n" +
                "| leftBrace               |             | \"" + leftBrace + "\"\n" +
                "+-------------------------+             +-------\n" +
                "| rightBrace              | std::string | \"" + rightBrace + "\"\n" +
                "+-------------------------+             |-------\n" +
                "| prompt                  |             | \"" + prompt + "\"\n" +
                "+-------------------------+-------------+-------\n" +
                "| promptInBrace           | bool        | \"" + std::to_string(promptInBrace) + "\"\n" +
                "+-------------------------+-------------+-------\n";
        return info;
    };

#endif //ASKER_DEBUG

};


#endif //ASKER_H
