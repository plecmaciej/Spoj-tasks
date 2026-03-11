import heapq

INF = 200000
def dijkstra(start, end, graph, n):
    distances = [INF] * (n + 1)
    visited = [False] * (n + 1)
    distances[start] = 0
    heap = [(0, start)]

    while heap:
        dist_u, u = heapq.heappop(heap)
        if visited[u]:
            continue
        visited[u] = True
        for v, cost in graph[u]:
            if distances[v] > dist_u + cost:
                distances[v] = dist_u + cost
                heapq.heappush(heap, (distances[v], v))
    return distances[end]
def main():
    try:
        s = int(input())
        for test in range(s):
            n = int(input())
            cities = {}
            graph = {i: [] for i in range(1, n + 1)}

            for i in range(1, n + 1):
                city_name = input().strip() # czy tutaj może zajść problem jesli nie zostanie podane zadne miasto
                if not city_name:
                    raise ValueError("Empty city name")
                cities[city_name] = i
                p = int(input())
                graph[i] = []
                for _ in range(p):
                    try:
                        neighbour, cost = map(int, input().split())
                        graph[i].append((neighbour, cost))
                    except ValueError:
                        raise ValueError(f"Invalid neighbour/cost input for city {city_name}")

            r = int(input())
            paths = []
            for _ in range(r):
                line = input().split()
                if len(line) != 2:
                    raise ValueError("Each path must have exactly 2 city names")
                paths.append(line)

            for start_name, end_name in paths:
                start = cities.get(start_name)
                end = cities.get(end_name)
                if start is None or end is None:
                    raise KeyError(f"City not found: {start_name} or {end_name}")
                print(dijkstra(start, end, graph, n))
    except Exception as e:
        print(f"Error: {e}")



if __name__ == "__main__":
    main()
