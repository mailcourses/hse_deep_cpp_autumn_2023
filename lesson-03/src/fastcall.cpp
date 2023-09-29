[[gnu::fastcall]]
void foo1(int x, int y, int z, int a)
{
}

void foo2(int x, int y, int z, int a)
{
}

void foo3(int x1, int x2, int x3, int x4, int x5, int x6, double x7, double x8)
{
}

void bar1()
{
    foo1(1, 2, 3, 4);
}

void bar2()
{
    foo2(1, 2, 3, 4);
}

void bar3()
{
    foo3(1, 2, 3, 4, 5, 6, 7.0f, 8.0f);
}
