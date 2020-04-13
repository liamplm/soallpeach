res = open('res').readlines()
test2 = open('test2.txt').readlines()

for i, n in enumerate(test2):
    if n != res[i]:
        print('found hell at', f'{i}: {n} != {res[i]}')
        break
print('all ok')

