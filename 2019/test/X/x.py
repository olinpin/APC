n = int(input())
experiments = [int(x) for x in input().split(" ")]

bacteriaCount = 1
for experiment in experiments:
    bacteriaCount *= 2
    bacteriaCount -= experiment
    if bacteriaCount < 0:
        print("error")
        break
else:
    print(bacteriaCount % (10**9 + 7))
