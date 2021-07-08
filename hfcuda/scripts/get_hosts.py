#!/usr/bin/python

import os

envar = 'LSB_MCPU_HOSTS'
enval = os.environ[envar]
hosts = enval.split(' ')[2:-1:2]

print '\n'.join(sorted(hosts))

