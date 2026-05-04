#include <iostream>
#include <unordered_set>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

bool isAdjacent(string a, string b) { //check if two words differ by 1 letter
    int diff = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) diff++;
    }
    return diff == 1;
}

vector<string> findWordLadder(string start, string end, unordered_set<string>& dict) {
    queue<vector<string>> q;
    q.push({start});

    dict.erase(start);

    while (!q.empty()) {
        vector<string> path = q.front();
        q.pop();

        string last = path.back();

        if (last == end) return path;

        for (auto it = dict.begin(); it != dict.end();) {
            if (isAdjacent(last, *it)) {
                vector<string> newPath = path;
                newPath.push_back(*it);
                q.push(newPath);
                it = dict.erase(it);
            } else {
                ++it;
            }
        }
    }

    return {};
}

int main() {
    cout << "=========================\n";
    cout << "   Word Ladder Solver\n";
    cout << "=========================\n\n";

    string start, end;

    cout << "Enter start word: ";
    cin >> start;

    cout << "Enter end word: ";
    cin >> end;

    if (start.length() != end.length()) {
        cout << "Words must be same length.\n";
        return 0;
    }

    unordered_set<string> dict;
    ifstream file("dictionary.txt");

    string word;
    while (file >> word) {
        if (word.length() == start.length()) {
            dict.insert(word);
        }
    }

    vector<string> result = findWordLadder(start, end, dict);

    if (result.empty()) {
        cout << "No path found.\n";
    } else {
        cout << "Path: ";
        for (string w : result) {
            cout << w << " ";
        }
        cout << endl;
    }

    return 0;
}