# Enter your code here. Read input from STDIN. Print output to STDOUT
import re

n = int(raw_input())
ipv4 = u'(\d+).(\d+).(\d+).(\d+)'
ipv6 = u'(.+):(.+):(.+):(.+):(.+):(.+):(.+):(.+)'
typ = 0
for i in xrange(n):
    ip_str = raw_input()
    match = re.findall(ipv4, ip_str)

    if match:
        for j in xrange(4):
            seg = int(match[0][j])
            if seg>=0 and seg<=255:
                pass
            else:
                typ = 1
                break
    else:
        typ = 1
    if typ == 1:
        print "Neither"
    else :
        print "IPv4"


'''
6
121.18.19.20
1211.18.19.20
121.1811.19.20
121.18.719.20
121.18.19.820
This line has junk text.
'''