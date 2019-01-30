# -*- conding: utf-8 -*-

raw = "g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."
print(raw + '\n')
def rot2(raw):
    for ch in raw:
        if ord(ch) in range(ord('a'),ord('z')+1):
            if ch == 'y':
                print('a', end = '')
            elif ch == 'z':
                print('b', end = '')
            else:
                print(chr(ord(ch)+2), end = '')
        else:
            print(ch, end = '')

rot2(raw)
print('\n')
rot2('map')