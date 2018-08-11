#!/usr/bin/env python
# -*- coding: utf-8 -*-

import string
import hashlib
import itertools
import re

def dict_pd_yield(strings, length):
    for x in itertools.product(strings, repeat=length):
        yield ''.join(x)
# def judgess(ss):
#     for x in ss:
#         if '0' <= x <= '9':
#             continue
#         return False
#     return True


# ss = ''.join([chr(x) for x in range(256)])
# ss = string.printable
ss =  string.letters + string.digits
# ss =  string.digits
# ss = string.hexdigits


while 1:
    prefix = raw_input("prefix: ")
    t = False
    h = hashlib.new('md5')
    for i in xrange(4, 100, 1):
        for s in dict_pd_yield(ss, i):
            h.update(s.encode('utf-8'))
            res = h.hexdigest()
            if res[:len(prefix)] == prefix:
                print s, ":", res
                # print "done"
                t = True
                break
        if t:
            break 
