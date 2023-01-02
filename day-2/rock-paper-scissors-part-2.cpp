#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

int main() {
    std::ios_base::sync_with_stdio(false); // avoid C stdio synchronization for efficiency
    std::cin.tie(NULL); // avoid flushing cout before cin calls for efficiency

    std::ifstream file("input.txt");

    std::map<char, int> cmap;

    cmap['A'] = 0;
    cmap['B'] = 1;
    cmap['C'] = 2;

    if (!file) return 0;

    int score = 0;

    std::string line;
    while(getline(file, line)) {
        std::stringstream stream(line);
        char opp_move, res;

        stream >> opp_move >> res;

        if (res == 'X') {
            score += ((cmap[opp_move] + 2) % 3 + 1);
        } else if (res == 'Y') {
            score += 3;
            score += (cmap[opp_move] + 1);

        } else {
            score += 6;
            score += ((cmap[opp_move] + 1) % 3 + 1);
        }
    }

    std::cout << score << std::endl;
}