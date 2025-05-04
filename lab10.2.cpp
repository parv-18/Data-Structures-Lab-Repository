/*program to find how many points will each player will have after each person writes down n distinct words of length 3*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;

    // Store words for each player
    vector<vector<string>> words(3, vector<string>(n));
    unordered_map<string, int> word_count;

    // Read input words and count frequency of each word
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> words[i][j];
            word_count[words[i][j]]++;
        }
    }

    // Initialize scores for each player
    vector<int> scores(3, 0);

    // Calculate scores based on word frequency
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            string word = words[i][j];
            if (word_count[word] == 1) {
                scores[i] += 3;
            } else if (word_count[word] == 2) {
                scores[i] += 1;
            }
        }
    }

    // Print scores for the current test case
    cout << scores[0] << " " << scores[1] << " " << scores[2] << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
