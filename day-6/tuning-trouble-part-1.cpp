#include <iostream>
#include <fstream>
#include <sstream>

#include <deque>

int main() {
    std::ifstream file("input.txt");
    if (!file) return 0;

    std::string line;
    getline(file, line);

    std::deque<char> buffer;

    buffer.push_back(line[0]);
    buffer.push_back(line[1]);
    buffer.push_back(line[2]);
    buffer.push_back(line[3]);

    std::cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << " " << buffer[3] << std::endl;

    if (buffer[0] != buffer[1] && buffer[1] != buffer[2] && buffer[2] != buffer[3] && buffer[0] != buffer[2] && buffer[0] != buffer[3] && buffer[1] != buffer[3]) {
        std::cout << 0 << std::endl;
        return 4;
    }

    for (int i = 4; i < line.size(); ++i) {
        buffer.pop_front();
        buffer.push_back(line[i]);

        std::cout << buffer[0] << " " << buffer[1] << " " << buffer[2] << " " << buffer[3] << std::endl;

        if (buffer[0] != buffer[1] && buffer[1] != buffer[2] && buffer[2] != buffer[3] && buffer[0] != buffer[2] && buffer[0] != buffer[3] && buffer[1] != buffer[3]) {
            std::cout << i + 1 << std::endl;
            return 0;
        }
    }

}