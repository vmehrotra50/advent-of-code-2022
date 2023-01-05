#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <deque>

std::vector<int> parseInput(std::string input) {
    std::vector<int> res;

    int j = 5; // first num starts at pos 5;

    while (isdigit(input[j])) {
        ++j;
    }

    res.push_back(stoi(input.substr(5, j + 1)));

    j = 12;
    
    while (isdigit(input[j])) {
        ++j;
    }

    res.push_back(stoi(input.substr(12, j + 1)) - 1);
    
    j = 17;
    
    while (j < input.size()) {
        ++j;
    }

    res.push_back(stoi(input.substr(17, j + 1)) - 1);

    return res;
}

int main() {
    std::ifstream file("input.txt");
    int n = 9; // 9 stacks of crates

    // 1. initialize an array of 9 deques
    std::deque<char> stacks[9];

    for (int i = 0; i < n; ++i) {
        stacks[i] = std::deque<char>();
    }

    std::string line;

    // Build the stacks
    for (int i = 0; i < 8; ++i) {
        getline(file, line);

        for (int j = 1; j < 35; j += 4) {
            if (line[j] != ' ') {
                stacks[(j - 1) / 4].push_back(line[j]);
            }
        }
    }

    // skip to start of instructions
    getline(file, line);
    getline(file, line);

    // perform instructions
    while (getline(file, line)) {
        std::vector<int> parsed = parseInput(line);
        
        std::deque<char> temp_deque;

        // FOR PART 2: SIMPLY CHANGE THE ORDER IN WHICH CRATES ARE MOVED
        // move from:
        for (int i = 0; i < parsed[0]; ++i) {
            temp_deque.push_back(stacks[parsed[1]].front());
            stacks[parsed[1]].pop_front();
        }

        // move to:
        for (int i = 0; i < parsed[0]; ++i) {
            stacks[parsed[2]].push_front(temp_deque.back());
            temp_deque.pop_back();
        }

    }

    std::string res = "";
    for (int i = 0; i < n; ++i) {
        if (stacks[i].size() > 0) {
            res += stacks[i].front();
        }
    }

    std::cout << res << std::endl;

}