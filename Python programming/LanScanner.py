# -*- coding=utf-8 -*-

import thread
import time
from subprocess import Popen,PIPE
def ip_check():
    check = Popen(['/bin/bash','-c','ping -c 2'+'127.0.0.1'],stdin=PIPE,stdout=PIPE)
    data = check.stdout.read()
    print data
