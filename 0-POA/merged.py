print("Enter the number of frames: ", end="")
capacity = int(input())
s = list(map(int, input("Enter the reference string: ").strip().split()))
print()

# FIFO Algorithm
print("FIFO Page Replacement Algorithm:")
f_fifo, fault_fifo, top_fifo = [], 0, 0
for i in s:
    if i not in f_fifo:
        if len(f_fifo) < capacity:
            f_fifo.append(i)
        else:
            f_fifo[top_fifo] = i
            top_fifo = (top_fifo + 1) % capacity
        fault_fifo += 1
    print("   %d\t\t" % i, end='')
    for x in f_fifo:
        print(x, end=' ')
    for x in range(capacity - len(f_fifo)):
        print(' ', end=' ')
    print("Yes" if i not in f_fifo else "No")
print("Total Requests: %d\nTotal Page Faults: %d\nFault Rate: %0.2f%%\n" % (len(s), fault_fifo, (fault_fifo / len(s)) * 100))

# LRU Algorithm
print("LRU Page Replacement Algorithm:")
f_lru, fault_lru, pf_lru = [], 0, 'No'
st_lru = []
for i in s:
    if i not in f_lru:
        if len(f_lru) < capacity:
            f_lru.append(i)
            st_lru.append(len(f_lru) - 1)
        else:
            ind = st_lru.pop(0)
            f_lru[ind] = i
            st_lru.append(ind)
        pf_lru = 'Yes'
        fault_lru += 1
    else:
        st_lru.append(st_lru.pop(st_lru.index(f_lru.index(i))))
        pf_lru = 'No'
    print("   %d\t\t" % i, end='')
    for x in f_lru:
        print(x, end=' ')
    for x in range(capacity - len(f_lru)):
        print(' ', end=' ')
    print(" %s" % pf_lru)
print("Total Requests: %d\nTotal Page Faults: %d\nFault Rate: %0.2f%%\n" % (len(s), fault_lru, (fault_lru / len(s)) * 100))

# Optimal Algorithm
print("Optimal Page Replacement Algorithm:")
f_optimal, fault_optimal, pf_optimal = [], 0, 'No'
occurance = [None for _ in range(capacity)]
for i in range(len(s)):
    if s[i] not in f_optimal:
        if len(f_optimal) < capacity:
            f_optimal.append(s[i])
        else:
            for x in range(len(f_optimal)):
                if f_optimal[x] not in s[i + 1:]:
                    f_optimal[x] = s[i]
                    break
                else:
                    occurance[x] = s[i + 1:].index(f_optimal[x])
            else:
                f_optimal[occurance.index(max(occurance))] = s[i]
        fault_optimal += 1
        pf_optimal = 'Yes'
    else:
        pf_optimal = 'No'
    print("   %d\t\t" % s[i], end='')
    for x in f_optimal:
        print(x, end=' ')
    for x in range(capacity - len(f_optimal)):
        print(' ', end=' ')
    print(" %s" % pf_optimal)
print("Total Requests: %d\nTotal Page Faults: %d\nFault Rate: %0.2f%%" % (len(s), fault_optimal, (fault_optimal / len(s)) * 100))
