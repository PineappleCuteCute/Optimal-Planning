#include <iostream>
#include <vector>
using namespace std;

vector<int> solve_jewelry_theft(int n, vector<int>& weights, vector<int>& values, int max_weight) {
    vector<vector<double>> dp(n + 1, vector<double>(max_weight + 1, 0));
    vector<vector<int>> take(n + 1, vector<int>(max_weight + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        int weight_i = weights[i - 1];
        double value_i = values[i - 1];
        
        for (int j = 0; j <= max_weight; ++j) {
            dp[i][j] = dp[i - 1][j];
            take[i][j] = 0;
            
            if (j >= weight_i) {
                if (dp[i][j] < dp[i - 1][j - weight_i] + value_i) {
                    dp[i][j] = dp[i - 1][j - weight_i] + value_i;
                    take[i][j] = 1;
                }
            }
            
            if (j >= 2 * weight_i) {
                if (dp[i][j] < dp[i - 1][j - 2 * weight_i] + 1.9 * value_i) {
                    dp[i][j] = dp[i - 1][j - 2 * weight_i] + 1.9 * value_i;
                    take[i][j] = 2;
                }
            }
            
            if (j >= 3 * weight_i) {
                if (dp[i][j] < dp[i - 1][j - 3 * weight_i] + 2.6 * value_i) {
                    dp[i][j] = dp[i - 1][j - 3 * weight_i] + 2.6 * value_i;
                    take[i][j] = 3;
                }
            }
        }
    }
    
    vector<int> result(n, 0);
    int remaining_weight = max_weight;
    
    for (int i = n; i > 0; --i) {
        result[i - 1] = take[i][remaining_weight];
        remaining_weight -= result[i - 1] * weights[i - 1];
    }
    
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
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
