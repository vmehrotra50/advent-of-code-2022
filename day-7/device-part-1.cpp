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

    map<string, int> file_system;

    string line;
    string current_dir;

    while (getline(file, line)) {
        vector<string> parsed;
        parse_line(line, parsed);

    }
}