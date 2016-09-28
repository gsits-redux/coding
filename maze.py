array_target = [1,2,5,2,5,0,1,5,6,1,5,6,2,4,3,1]

bad_set = set()

i = 0

while i < len(array_target):
    if array_target[i] == 0:
        bad_set.add(i)
    elif array_target[i] + i > len(array_target):
        bad_set.add(i)
    i += 1

while True:
    i = 0
    no_change = True
    while i < len(array_target):
        if (i not in bad_set) and (array_target[i] + i in bad_set):
            bad_set.add(i)
            no_change = False
        i +=1
    if no_change:
        break

i = 0

while i < len(array_target):
    if i not in bad_set:
        print i, array_target[i]
    i += 1





