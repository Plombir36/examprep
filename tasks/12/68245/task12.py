def isprime(n):
    if n <= 1:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True

s = '0'+'4'*31+'30'

for i in range(15):
    s = s.replace("44", "34", 1)
    if (isprime(sum(map(int, s)) - 2)):
        print(s.count('3'))
        break

for i in range(15):
    s = s.replace("34", "33", 1)
    if (isprime(sum(map(int, s)) - 2)):
        print(s.count('3'))
        break
