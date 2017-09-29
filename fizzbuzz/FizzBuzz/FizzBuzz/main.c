//
//  main.c
//  FizzBuzz
//
//  Created by Ridhwaan on 9/20/17.
//  Copyright © 2017 Ridhwaan. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    int i;
    for (i = 0 ; i < 100; ++i) {
        
        if (isDivisible3(&i) == 1){
        
            printf("Fizz");
        }
        
        if (isDivisible5(&i) == 1){
            
            printf("Buzz");
        }
        
    }
    return 0;
}

        int isDivisible5(int* i){
            int value = *i;
    if (value % 5 == 0){
                return 1;
            
            }
            
            return 0;

        }

        int isDivisible3(int* i){
        int value = *i;
    if (value % 3 == 0){
        return 1;
        
        }
    
    return 0;
    
    }


        int isDivisible3And5(int* i){
        int value = *i;
    if (value % 3 == 0 && value % 5 == 0){
        return 1;
    }
    
    return 0;
    
}

