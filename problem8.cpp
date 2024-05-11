#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidPart(const string& part) {
    // Check if the part is a valid number between 0 and 255
    if (part.size() > 1 && part[0] == '0') {
        // Leading zeros are not allowed except for '0' itself
        return false;
    }
    int num = stoi(part);
    return num >= 0 && num <= 255;
}

void generateIP(vector<string>& result, string& s, int start, int parts, string& current) {
    // Base case: if we have reached the end of the string and formed 4 parts
    if (start == s.size() && parts == 4) {
        // Add the current combination to the result
        result.push_back(current);
        return;
    }

    // If we have formed 4 parts but haven't reached the end of the string, return
    if (parts == 4 || start == s.size()) {
        return;
    }

    // Try partitioning the string from the current position
    for (int i = 1; i <= 3 && start + i <= s.size(); ++i) {
        string part = s.substr(start, i);
        if (isValidPart(part)) {
            // Add the part to the current combination and continue exploring
            string temp = current;
            if (!temp.empty()) {
                temp += ".";
            }
            temp += part;
            generateIP(result, s, start + i, parts + 1, temp);
        }
    }
}

vector<string> genIp(string& s) {
    vector<string> result;
    string current;
    generateIP(result, s, 0, 0, current);
    return result.empty() ? vector<string>{"-1"} : result;
}

int main() {
    // Example usage
    string S = "1111";
    vector<string> IPs = genIp(S);
    for (const string& ip : IPs) {
        cout << ip << endl;
    }
    return 0;
}
