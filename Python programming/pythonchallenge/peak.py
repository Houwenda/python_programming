# -*- coding: utf-8 -*-
import pickle
with open('banner.p', 'rb') as f:
    r = pickle.load(f)
    #print(r)
    for line in r:
        for t in line:
            for count in range(t[1]):
                print(t[0], end = '')
        print('')