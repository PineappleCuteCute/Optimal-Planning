#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Jewelry {
    int weight;
    double value;
    int count1;
    int count2;
    int count3;
};

bool compare(Jewelry& j1, Jewelry& j2) {
    return j1.value > j2.value;
}

vector<int> solve_jewelry_theft(int n, vector<int>& weights, vector<int>& values, int max_weight) {
    vector<Jewelry> jewels(n);
    
    for (int i = 0; i < n; ++i) {
        jewels[i].weight = weights[i];
        jewels[i].value = values[i];
        jewels[i].count1 = 0;
        jewels[i].count2 = 0;
        jewels[i].count3 = 0;
        
        if (max_weight >= jewels[i].weight) {
            jewels[i].count1 = 1;
            max_weight -= jewels[i].weight;
        }
        
        if (max_weight >= 2 * jewels[i].weight) {
            jewels[i].count2 = 1;
            max_weight -= 2 * jewels[i].weight;
        }
        
        if (max_weight >= 3 * jewels[i].weight) {
            jewels[i].count3 = 1;
            max_weight -= 3 * jewels[i].weight;
        }
    }
    
    sort(jewels.begin(), jewels.end(), compare);
    
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = jewels[i].count1 + jewels[i].count2 * 2 + jewels[i].count3 * 3;
    }
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> weights(n);
    vector<int> values(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }
    
    for (int i = 0; i < n; ++i) {
        cin >> values[i];
    }
    
    int max_weight;
    cin >> max_weight;
    
    vector<int> solution = solve_jewelry_theft(n, weights, values, max_weight);
    
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        cout << solution[i] << " ";
    }
    cout << endl;
    
    return 0;
}
