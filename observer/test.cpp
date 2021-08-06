#include <iostream>

#include "observer.hpp"


int main() {
    //bes::Subject test;
    // this shit gonna leak xD
    bes::Subject *sub = new bes::Subject;
    delete sub;
    return 0;
}
