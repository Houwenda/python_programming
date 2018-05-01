# -*- coding=utf-8 -*-

import thread
import time
import re
import os
def ip_check(ip):
    command = 'ping -n 1 '+ ip
    check = os.popen(command,'r',-1)
    data = check.read()
    if 'TTL' in data:
        print '%s is up'%ip

def main():
    for i in range(1,255):
        ip = '192.168.1.' + str(i)
        thread.start_new_thread(ip_check, (ip,))
        time.sleep(0.1)

if __name__ == '__main__':
    main()
