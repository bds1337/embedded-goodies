#include <stdio.h>

#define lambda(ret_type, _body) ({ ret_type _ _body _; })

#define lambda_2(_body) ({ _body _;})

int main() 
{
    int (*max)(int, int) = lambda(int,
                         (int x, int y) {
                             return x > y ? x : y;
                         });


    int max_value = 

    //int max_value = max(1, 2);
    printf("%u\n", max_value);
    return 0;
}
