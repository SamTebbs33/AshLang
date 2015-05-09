#include "dec.h"

A::A(){

}

B::B() : A(){

}

C::C() : B(){

}

void A::foo(){

}

void C::foo(){
    printf("Works!");
}
