# Enter your code here. Read input from STDIN. Print output to STDOUT
import re

n = int(raw_input())
ipv4 = u'(\d+).(\d+).(\d+).(\d+)'
ipv6 = u'(.+):(.+):(.+):(.+):(.+):(.+):(.+):(.+)'

for i in xrange(n):
    typ = 0
    ip_str = raw_input()
    match = re.findall(ipv4, ip_str)

    if match:
        for j in xrange(4):
            try:
                seg = int(match[0][j])
            except ValueError:
                typ = 1
                break
            if seg>=0 and seg<=255:
                pass
            else:
                typ = 1
                break
    else:
        typ = 1


    if typ == 0:
        print "IPv4"
        continue

    match = re.findall(ipv6, ip_str)

    if match:
        for j in xrange(8):
            try:
                seg = int(match[0][j], base=16)
            except ValueError:
                typ = 2
                break
            if seg>=0 and seg<=65535:
                pass
            else:
                typ = 2
                break
    else:
        typ = 2

    if typ == 1:
        print "IPv6"
    else:
        print "Neither"
