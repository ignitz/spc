# -*- coding: utf-8 -*-
from __future__ import print_function
import sys
import os
from shutil import copyfile


def touch(fname, times=None):
    fhandle = open(fname, 'a')
    try:
        os.utime(fname, times)
    finally:
        fhandle.close()


def main():
    """
    python create.py $number
    """
    args = sys.argv[1:]

    if len(args) > 0:
        if not os.path.isdir(args[0]):
            id_number = args[0]
            os.mkdir(id_number)
            copyfile('../../template/c.c', id_number + '/' + id_number + '.c')
            copyfile('../../template/cpp.cpp',
                     id_number + '/' + id_number + '.cpp')
            copyfile('../../template/python.py',
                     id_number + '/' + id_number + '.py')
            copyfile('../../template/node.js',
                     id_number + '/' + id_number + '.js')
            os.chdir(id_number)
            os.mkdir('tests')
            os.chdir('tests')
            touch('input1.txt')
            touch('output1.txt')
            touch('temp.txt')


if __name__ == '__main__':
    main()
