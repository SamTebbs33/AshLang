#include <stdio.h>

class A{
public:
    virtual void foo();
    A();
};

class B : public A{
public:
    B();
};

class C : public B{
public:
    C();
    virtual void foo();
};
