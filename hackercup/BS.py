n = int(raw_input())
for i in xrange(n):
    s = raw_input()
    beauty = [0] * 26
    for c in s:
        if c <= 'Z' and c >= 'A':
            beauty[ord(c) - ord('A')] += 1
        elif c <= 'z' and c >= 'a':
            beauty[ord(c) - ord('a')] += 1
    beauty.sort(reverse=True)
    ret = 0
    for j in xrange(26):
        if beauty[j] == 0:
            break
        ret += beauty[j] * (26 - j)
    print "Case #%d: %d" % (i + 1, ret)
