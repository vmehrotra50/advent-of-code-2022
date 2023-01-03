#include <iostream>
#include <sstream>
#include <fstream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false); // avoid C stdio synchronization for efficiency
    std::cin.tie(NULL); // avoid flushing cout before cin calls for efficiency

    std::ifstream file("input.txt");
    if (!file) return 0;

    std::string line;
    int score = 0;

    while (getline(file, line)) {
        std::stringstream stream(line);
        std::set<char> s;

        char nextChar;

        for (int i = 0; i < line.length() / 2; ++i) {
            stream >> nextChar;
            s.insert(nextChar);
        }

        for (int i = 0; i < line.length() / 2; ++i) {
            stream >> nextChar;
            if (s.find(nextChar) != s.end()) {
                if (nextChar >= 97) {
                    score += (nextChar - 96);
                } else {
                    score += (nextChar - 38);
                }
                break;
            }
        }
    }

    std::cout << score << std::endl;
}

