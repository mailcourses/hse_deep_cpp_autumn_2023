#! /usr/bin/env python3

import cffi

def main():
    ffi = cffi.FFI()
    lib = ffi.dlopen('./libutils.so')
    ffi.cdef('''struct Point{
        int x;
        int y;
    };
    int area(struct Point* p1, struct Point*p2);
    int sum(int* arr, int len);''')

    p1 = ffi.new('struct Point*')
    p2 = ffi.new('struct Point*')
    p1.x, p1.y = 10, 10
    p2.x, p2.y = 0, -5
    res = lib.area(p1, p2)
    print(f'{res=}')

    lst = list(range(5, 10))
    arr = ffi.new('int[]', lst)
    res = lib.sum(arr, len(arr))
    print(f"Sum of array's elements is {res}")

if __name__ == "__main__":
    main()
