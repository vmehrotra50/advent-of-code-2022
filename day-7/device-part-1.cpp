#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <map>

using namespace std;

void parse_line(string& s, vector<string>& out) {
    stringstream ss(s);

    string s;
    while (getline(ss, s, ' ')) {
        out.push_back(s);
    }
}

int main() {
    ifstream file("input.txt");
    if (!file) return 0;

    map<string, vector<string>> file_system;
    map<string, int> sizes;

    string line;

    getline(file, line); // skip over cd to /
    string current_dir = "/";

    while (true) {
        vector<string> parsed;
        parse_line(line, parsed);

        if (parsed[0] == "$") {
            if (parsed[1] == "cd") {
                if (parsed[2] == "..") {
                    int i = current_dir.length() - 1;
                    while (current_dir[i] != '/') --i;
                    current_dir = current_dir.substr(i + 1, current_dir.length());
                } else {
                    file_system[current_dir + parsed[2] + "/"] = vector<string>();
                    sizes[current_dir + parsed[2] + "/"] = 0;
                }
            } else if (parsed[2] == "ls") {
                getline(file, line);
                while (line[0] != '$') {
                    if (line.substr(0, 4) != "dir") {
                        sizes[current_dir] += 
                    }
                    if (!getline(file, line)) {
                        // TODO: PRINT OUTPUT
                    }
                }
            } 
        }

    }
}