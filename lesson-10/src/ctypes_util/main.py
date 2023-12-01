#! /usr/bin/env python3

import ctypes

def c_strstr():
    lib = ctypes.cdll.LoadLibrary('/lib64/libc-2.17.so')
    lib.strstr.restype = ctypes.c_char_p
    lib.strstr.argstype = [ctypes.c_char_p, ctypes.c_char_p]
    res = lib.strstr(b'banana', b'ana')
    print(res)
    res = lib.strstr(b'banana', b'bbbb')
    print(res)

def main():
    lib = ctypes.CDLL('./libutils.so')
    lib.sum.restype = ctypes.c_int
    lib.sum.argstype = [ctypes.POINTER(ctypes.c_int), ctypes.c_int]

    lst = list(range(0, 6))
    n = len(lst)
    arr_type = ctypes.c_int * n
    s = lib.sum(arr_type(*lst), n)
    print(f"sum of {lst} is {s}")

    #c_strstr()

    lib.foo.restype = ctypes.c_int
    lib.foo.argstype = [ctypes.c_int]
    for i in range(5):
        print(f"#{i} {lib.foo(i)}")

    lib2 = ctypes.CDLL('./libutils.so.2')
    lib2.convert_to_string.restype = ctypes.c_void_p
    lib2.convert_to_string.argstype = [ctypes.c_int]

    lib2.free_memory.restype = None
    lib2.free_memory.argstype = [ctypes.c_void_p]

    res_p = lib2.convert_to_string(100500)
    print(type(res_p))
    res = ctypes.c_char_p(res_p).value
    print(res)
    lib2.free_memory(ctypes.c_char_p(res_p))

if __name__ == "__main__":
    main()
