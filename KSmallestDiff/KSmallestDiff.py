import heapq

def FindKLowestDiff(data, k):
    h_neg = []
    h_pos = []
    n = len(data)
    print n
    len_neg = 0
    len_pos = 0

    for value in data:
        if value <= n:
            heapq.heappush(h_neg, n-value)
            len_neg += 1
        else:
            heapq.heappush(h_pos, value-n)
            len_pos += 1

    count = 0

    while len_neg > 0 and len_pos > 0:
        val_neg = h_neg[0]
        val_pos = h_pos[0]
        if val_neg <= val_pos:
            print n - val_neg
            heapq.heappop(h_neg)
            len_neg -= 1
        else:
            print n + val_pos
            heapq.heappop(h_pos)
            len_pos -= 1
        count += 1
        if count == k:
            break

    if (len_neg > 0):
        print "extra"
        for x in range(1, k - count):
            print heapq.heappop(h_pos)

    if (len_pos > 0):
        print "extra2"
        for x in range(1, k - count):
            print heapq.heappop(h_neg)


FindKLowestDiff([4, 9, 12, 14, 20, 64, 143, 7, 89, 100