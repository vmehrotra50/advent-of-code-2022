#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false); // avoid C stdio synchronization for efficiency
    std::cin.tie(NULL); // avoid flushing cout before cin calls for efficiency

    std::ifstream file("input.txt");

    if (!file) return 0;

    int score = 0;
    char opp_move, your_move;

    std::string line;
    while(getline(file, line)) {
        std::stringstream stream(line);
        char opp_move, your_move;

        stream >> opp_move >> your_move;

        if (your_move == 'X') {
            score += 1;
            
            if (opp_move == 'A') {
                score += 3;
            } else if (opp_move == 'C') {
                score += 6;
            }

        } else if (your_move == 'Y') {
            score += 2;

            if (opp_move == 'B') {
                score += 3;
            } else if (opp_move == 'A') {
                score += 6;
            }
        } else if (your_move == 'Z') {
            score += 3;

            if (opp_move == 'C') {
                score += 3;
            } else if (opp_move == 'B') {
                score += 6;
            }
        }
    }

    std::cout << score << std::endl;
}