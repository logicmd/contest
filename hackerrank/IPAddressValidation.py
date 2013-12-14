# Enter your code here. Read input from STDIN. Print output to STDOUT
import re
n = int(raw_input())
ipv4 = u'(\d+).(\d+).(\d+).(\d+)'
ipv6 = u'(.+):(.+):(.+):(.+):(.+):(.+):(.+):(.+)'
for i in xrange(n):
    ip_str = raw_input()
    re.findall(ipv4, ip_str)
