#include <iostream>
#include <fstream>
#include <sstream>

#include <deque>
#include <set>

bool is_unique(std::deque<char> buffer) {
    std::set<char> set;

    for (int i = 0; i < buffer.size(); ++i) {
        set.insert(buffer[i]);
    }

    return set.size() == buffer.size();
}


int main() {
    std::ifstream file("input.txt");
    if (!file) return 0;

    std::string line;
    getline(file, line);

    std::deque<char> buffer;

    for (int i = 0; i < 14; ++i) {
        buffer.push_back(line[i]);
    }

    if (is_unique(buffer)) {
        std::cout << 0 << std::endl;
        return 14;
    }

    for (int i = 14; i < line.size(); ++i) {
        buffer.pop_front();
        buffer.push_back(line[i]);

        if (is_unique(buffer)) {
            std::cout << i + 1 << std::endl;
            return 0;
        }
    }

}