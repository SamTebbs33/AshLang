#include "dec.h"
#include <vector>

std::vector<B*>* vec = new std::vector<B*>();

void bar(){
    if(vec){
        for(auto it = vec->begin(); it != vec->end(); it++){
            if((*it)){
                printf("Not null\n");
                (*it)->foo();
                printf("Done\n");
            }
        }
    }
}

int main(int argc, char const *argv[]) {
    vec->push_back(new C());
    bar();
    return 0;
}
