def solve_jewelry_theft(n, weights, values, max_weight):
    dp = [[0] * (max_weight + 1) for _ in range(n + 1)]
    take = [[0] * (max_weight + 1) for _ in range(n + 1)]
    
    for i in range(1, n + 1):
        weight_i, value_i = weights[i - 1], values[i - 1]
        
        for j in range(max_weight + 1):
            dp[i][j] = dp[i - 1][j]
            take[i][j] = 0
            
            if j >= weight_i:
                if dp[i][j] < dp[i - 1][j - weight_i] + value_i:
                    dp[i][j] = dp[i - 1][j - weight_i] + value_i
                    take[i][j] = 1
            
            if j >= 2 * weight_i:
                if dp[i][j] < dp[i - 1][j - 2 * weight_i] + 1.9 * value_i:
                    dp[i][j] = dp[i - 1][j - 2 * weight_i] + 1.9 * value_i
                    take[i][j] = 2

            if j >= 3 * weight_i:
                if dp[i][j] < dp[i - 1][j - 3 * weight_i] + 2.6 * value_i:
                    dp[i][j] = dp[i - 1][j - 3 * weight_i] + 2.6 * value_i
                    take[i][j] = 3

    result = [0] * n
    remaining_weight = max_weight
    
    for i in range(n, 0, -1):
        result[i - 1] = take[i][remaining_weight]
        remaining_weight -= result[i - 1] * weights[i - 1]

    return result

n = int(input().strip())
weights = list(map(int, input().strip().split()))
values = list(map(int, input().strip().split()))
max_weight = int(input().strip())

solution = solve_jewelry_theft(n, weights, values, max_weight)
print(n)
print(" ".join(map(str, solution)))
