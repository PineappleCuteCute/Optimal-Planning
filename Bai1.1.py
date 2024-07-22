from ortools.linear_solver import pywraplp

def solve_max_profit(n, areas, revenue_rice, revenue_potato, revenue_cassava, costs, limits):
    b, c, d = costs
    D, E, G = limits

    solver = pywraplp.Solver.CreateSolver('SCIP')
    if not solver:
        return None

    x = [solver.IntVar(0, areas[i], f'x{i}') for i in range(n)]
    y = [solver.IntVar(0, areas[i], f'y{i}') for i in range(n)]
    z = [solver.IntVar(0, areas[i], f'z{i}') for i in range(n)]

    for i in range(n):
        solver.Add(x[i] + y[i] + z[i] == areas[i])

    solver.Add(solver.Sum(x) <= D)
    solver.Add(solver.Sum(y) <= E)
    solver.Add(solver.Sum(z) <= G)

    objective = solver.Objective()
    for i in range(n):
        objective.SetCoefficient(x[i], revenue_rice[i] - b)
        objective.SetCoefficient(y[i], revenue_potato[i] - c)
        objective.SetCoefficient(z[i], revenue_cassava[i] - d)
    objective.SetMaximization()

    status = solver.Solve()

    if status == pywraplp.Solver.OPTIMAL:
        return solver.Objective().Value()
    else:
        return None

def read_input():
    n = int(input().strip())
    areas = list(map(int, input().strip().split()))
    revenue_rice = list(map(int, input().strip().split()))
    revenue_potato = list(map(int, input().strip().split()))
    revenue_cassava = list(map(int, input().strip().split()))
    costs = list(map(int, input().strip().split()))
    limits = list(map(int, input().strip().split()))
    return n, areas, revenue_rice, revenue_potato, revenue_cassava, costs, limits

n, areas, revenue_rice, revenue_potato, revenue_cassava, costs, limits = read_input()

max_profit = solve_max_profit(n, areas, revenue_rice, revenue_potato, revenue_cassava, costs, limits)
print(int(max_profit))
