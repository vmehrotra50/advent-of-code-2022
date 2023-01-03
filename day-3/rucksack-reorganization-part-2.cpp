#include <iostream>
#include <sstream>
#include <fstream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false); // avoid C stdio synchronization for efficiency
    std::cin.tie(NULL); // avoid flushing cout before cin calls for efficiency

    std::ifstream file("input.txt");
    if (!file) return 0;

    std::string line1, line2, line3;
    int score = 0;

    while (getline(file, line1) && getline(file, line2) && getline(file, line3)) {
        std::stringstream stream1(line1);
        std::stringstream stream2(line2);
        std::stringstream stream3(line3);
        
        std::set<char> s1;
        std::set<char> s2;
        std::set<char> s3;

        char nextChar;

        while (stream1 >> nextChar) {
            s1.insert(nextChar);
        }

        while (stream2 >> nextChar) {
            s2.insert(nextChar);
        }

        while (stream3 >> nextChar) {
            s3.insert(nextChar);
        }

        std::set<char>::iterator iterator;

        for (iterator = s1.begin(); iterator != s1.end(); iterator++) {
            if (s2.find(*iterator) != s2.end() && s3.find(*iterator) != s3.end()) {
                if (*iterator >= 97) {
                    score += (*iterator - 96);
                } else {
                    score += (*iterator - 38);
                }
                break;
            }
        }
    }

    std::cout << score << std::endl;
}

