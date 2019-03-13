#!/usr/bin/python

import os

cmp = 322424845
for i in range(0, 21):
    num = cmp - i
    cmd = "python -c \'print " + str(num) + "\'"
    bin_path = " | /home/users/level03/level03"
    playload = cmd + bin_path
    print "vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv"
    print num
    os.system(playload)
    print "\n"
