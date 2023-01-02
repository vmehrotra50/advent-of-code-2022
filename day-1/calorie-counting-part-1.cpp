#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false); // avoid C stdio synchronization for efficiency
    std::cin.tie(NULL); // avoid flushing cout before cin calls for efficiency

    std::ifstream file("input.txt");

    if (!file) return 0;

    std::string line;
    int max;
    int running_sum = 0;
    while (getline(file, line)) {
        std::stringstream stream(line);
        int num;
        if (!(stream >> num)) {
            max = std::max(max, running_sum);
            running_sum = 0;
        } else {
            running_sum += num;
        }
    }

    std::cout << max << std::endl;
}
