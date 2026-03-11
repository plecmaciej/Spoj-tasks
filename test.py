import random

def generate_undirected_test_case_file(filename="input.txt",
                                       n_cities=10,
                                       max_neighbors=4,
                                       max_cost=20,
                                       n_queries=5):
    """
    Generuje test case w formacie SPOJ-like z grafem nieskierowanym
    i zapisuje go do pliku `filename`.
    """
    city_names = [f"city{i}" for i in range(1, n_cities + 1)]

    lines = []

    # Header
    lines.append("1")            # liczba testów
    lines.append(str(n_cities))  # liczba miast

    # Tworzymy pustą strukturę sąsiedztwa
    neighbors_dict = {i: set() for i in range(1, n_cities + 1)}
    costs_dict = {}

    for i in range(1, n_cities + 1):
        n_neighbors = random.randint(0, min(max_neighbors, n_cities - 1))
        while len(neighbors_dict[i]) < n_neighbors:
            neighbor = random.randint(1, n_cities)
            if neighbor != i:
                # dodajemy krawędź w obie strony
                neighbors_dict[i].add(neighbor)
                neighbors_dict[neighbor].add(i)
                # losujemy koszt i zapisujemy dla obu kierunków
                cost = random.randint(1, max_cost)
                costs_dict[(i, neighbor)] = cost
                costs_dict[(neighbor, i)] = cost

    # Wypisujemy miasta i sąsiadów
    for i in range(1, n_cities + 1):
        lines.append(city_names[i-1])
        n_neighbors = len(neighbors_dict[i])
        lines.append(str(n_neighbors))
        for neighbor in neighbors_dict[i]:
            lines.append(f"{neighbor} {costs_dict[(i, neighbor)]}")

    # Zapytania
    lines.append(str(n_queries))
    for _ in range(n_queries):
        start = random.choice(city_names)
        end = random.choice(city_names)
        lines.append(f"{start} {end}")

    # Zapis do pliku
    with open(filename, "w") as f:
        f.write("\n".join(lines))

    print(f"Test case zapisany do pliku: {filename}")


if __name__ == "__main__":
    # Przykład: graf 6 miast, max 3 sąsiadów, max waga 20, 5 zapytań
    generate_undirected_test_case_file(n_cities=7000, max_neighbors=400, max_cost=200, n_queries=1000)