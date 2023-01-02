#include <iostream>
#include <fstream>
#include <sstream>

int main() {
    std::ios_base::sync_with_stdio(false); // avoid C stdio synchronization for efficiency
    std::cin.tie(NULL); // avoid flushing cout before cin calls for efficiency

    std::ifstream file("input.txt");

    if (!file) return 0;

    std::string line;
    int max = 0;
    int running_sum = 0;
    int max_arr[3] = {0, 0, 0};


    while (getline(file, line)) {
        std::stringstream stream(line);
        int num;
        if (!(stream >> num)) {
            std::cout << max_arr[0] << " " << max_arr[1] << " " << max_arr[2] << std::endl;
            for (int i = 0; i < 3; ++i) {
                if (running_sum > max_arr[i]) {
                    max += running_sum;
                    max -= max_arr[2];

                    for (int j = 2; j >= i + 1; --j) {
                        max_arr[j] = max_arr[j - 1];
                    }
                    max_arr[i] = running_sum;
                    running_sum = 0;
                    break;
                }
            }

            running_sum = 0;
        } else {
            running_sum += num;
        }

    }


    std::cout << max_arr[0] + max_arr[1] + max_arr[2] << std::endl;
}
