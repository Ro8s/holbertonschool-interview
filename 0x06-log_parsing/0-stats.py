#!/usr/bin/python3
""" parselog project """
import sys


cont = 0
size = 0
status = {'200': 0, '301': 0, '400': 0, '401': 0,
          '403': 0, '404': 0, '405': 0, '500': 0}
men = ['200', '301', '400', '401', '403', '404', '405', '500']
try:
    for line in sys.stdin:
        cont += 1
        sp = line.split(' ')
        if len(sp) > 2:
            size += int(sp[-1])
            if sp[-2] in status:
                status[sp[-2]] += 1
        if cont % 10 == 0:
            print("File size: {}".format(size))
            for num in men:
                if status[num]:
                    print("{}: {}".format(num, status[num]))

except KeyboardInterrupt:
    pass

finally:
    print("File size: {}".format(size))
    for num in men:
        if status[num]:
            print("{}: {}".format(num, status[num]))
