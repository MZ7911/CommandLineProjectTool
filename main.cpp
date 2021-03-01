#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <iomanip>
using namespace std;

int getInteger(string prompt = "") {
    int value;
    while (true) {
        cout << prompt;
        string line;
        getline(std::cin, line);
        istringstream stream(line);
        stream >> value;
        if (!stream.fail() && stream.eof()) {
            break;
        }
        cout << "Illegal integer format. Please try again." << endl;
    }
    return value;
}

int main() {
    while (true) {
        int nData = getInteger("#ENTER nData: ");
        map<int, int> data;
        for (int i = 0; i < nData; i++) {
            cout << "i = " << i << endl;
            int key = getInteger("#ENTER key: ");
            int value = getInteger("#ENTER value: ");
            data[key] = value;
        }
        for (pair<int, int> e : data) {
            cout << setw(3) << e.first << " | " << string(e.second, '*') << endl;
        }
        cout << "#QUIT(Enter Q to quit)? ";
        string str;
        getline(cin, str);
        if (str == "q" || str == "Q") {
            break;
        }
    }
    return 0;
}
