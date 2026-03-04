"""
def main2():
    number = input()
    wartosci = input().split()
    minimum = int(wartosci[0])
    maximum = int(wartosci[0])
    min_places = [0]
    max_places = [0]
    print(wartosci)
    for i in range(1,len(wartosci)):
        integer = int(wartosci[i])
        if minimum > integer:
            minimum = integer
            min_places = [i]
        elif maximum < integer:
            maximum = integer
            max_places = [i]
        elif minimum == integer:
            min_places.append(i)
        elif maximum == integer:
            max_places.append(i)
    str_min = str(minimum)
    str_max = str(maximum)

    for max in max_places:
        wartosci[max] = str_min

    for min in min_places:
        wartosci[min] = str_max

    print(maximum, minimum, max_places, min_places, wartosci)

"""

def main():
    n = int(input())
    arr = list(map(int, input().split()))

    minimum = min(arr)
    maximum = max(arr)

    for i in range(n):
        if arr[i] == minimum:
            arr[i] = maximum
        elif arr[i] == maximum:
            arr[i] = minimum

    print(*arr)


if __name__ == "__main__":
    main()
