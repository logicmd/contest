import itertools

def get(s1, s2o, m, l):
    for s2 in itertools.permutations(s2o):
        impossible = False
        s = []
        for i in xrange(m):

            str_list = []
            if impossible :
                break
            for j in xrange(l):
                if s1[i][j] != '?' and s2[i][j] != '?' :
                    if s1[i][j] != s2[i][j] :
                        impossible = True
                        break
                    else :
                        str_list.append(s1[i][j])
                else :
                    if s1[i][j] == '?' and s2[i][j] != '?' :
                        str_list.append(s2[i][j])
                    elif s2[i][j] == '?' and s1[i][j] != '?' :
                        str_list.append(s1[i][j])
                    else :
                        impossible = True # there's to much possibilities in fact
                        break
            s.append(''.join(str_list))

        if not impossible:
            return ''.join(s)

    return 'IMPOSSIBLE'


T = int(raw_input())
for t in xrange(T):
    m = int(raw_input())
    k1 = raw_input()
    k2 = raw_input()
    l = len(k1) / m

    s1 = []
    s2 = []
    for i in xrange(m):
        s1.append(k1[i*l:(i+1)*l])
        s2.append(k2[i*l:(i+1)*l])

    # print s1
    # print s2

    print "Case #%d: %s" % (t + 1, get(s1, s2, m, l))