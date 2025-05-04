/*program to utilize c++ STL and find the largest amount of blocks you can have on the tower 1 after the moves*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxBlocksOnTower1(vector<int>& towers) {
    int n = towers.size();
    
    // The maximum number of blocks that can be collected on tower 1
    int maxBlocks = towers[0];

    // Sort towers in descending order to move blocks optimally
    sort(towers.begin() + 1, towers.end(), greater<int>());

    // Move blocks from other towers to tower 1
    for (int i = 1; i < n; i++) {
        if (towers[i] < maxBlocks) break;
        maxBlocks += towers[i];
    }

    return maxBlocks;
}

int main() {
    int n;
    cout << "Enter number of towers: ";
    cin >> n;

    vector<int> towers(n);
    cout << "Enter number of blocks in each tower: ";
    for (int i = 0; i < n; i++) {
        cin >> towers[i];
    }

    int result = maxBlocksOnTower1(towers);
    cout << "Maximum blocks on tower 1: " << result << endl;

    return 0;
}
