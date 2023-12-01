
cdef float global_var = 3.1415

cpdef mult(int end):
    cdef int y = 1
    for i in range(1, end):
        y *= i
    return y

def test(int i):
    return str(i)

cpdef fibonacci(int n):
    if n < 2:
        return 1
    return fibonacci(n-2) + fibonacci(n-1)
