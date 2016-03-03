#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <inttypes.h>

void fibbout(int n) {
    //initialize divisibility and prime check iterators
    int divi = 0, primei = 0;
    //initialize Fibonacci number fn as largest non-arbitrary data type
    //fn1 and fn2 are the previous 2 values in the sequence
    uint64_t fn, fn1 = 0, fn2 = 1; 
    //3s and 5s divisibility occurs at regular intervals. Rather than using the
    //modulo operator to check for divisibility, the regular interval is precomputed
    //to save time during the run
    _Bool div3[20] = {1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};
    _Bool div5[20] = {1,0,0,0,0,1,0,0,0,0,1,0,0,0,0,1,0,0,0,0};
    //only 49 known primes exist in the Fibonacci sequence. Rather than performing
    //fast deterministic prime checking algorithms, which at best run in O(log(n)^6)ish
    //the program instead checks vs this array
    uint32_t primeind[49] = {3, 4, 5, 7, 
    11, 13, 17, 23, 
    29, 43, 47, 83, 
    131, 137, 359, 431, 
    433, 449, 509, 569, 
    571, 2971, 4723, 5387, 
    9311, 9677, 14431, 25561, 
    30757, 35999, 37511, 50833, 
    81839, 104911, 130021, 148091, 
    201107, 397379, 433781, 590041, 
    593689, 604711, 931517, 1049897, 
    1285607, 1636007, 1803059, 1968721,
    2904353};
    
    for(uint32_t i=0;i<n;i++){
        //case for first two values which cannot be defined by recurse relation alone
        if(i<=1){
            fn = i;
            //0 and 1 are known to be not prime and not multiples of 3 or 5
            printf("%" PRIu64 "\n",fn);
        }
        //case for all others
        else{
            //calculating via summation of previous terms
            fn = fn1 + fn2;
            fn1 = fn2;
            fn2 = fn;
            //check against primes
            if(primeind[primei]==i){
                printf("BuzzFizz\n");
                //increment iterator so it looks at the next prime index
                primei++;
            }
            else{
                //check for special divisible by 3s and 5s case
                //from inspection this occurs every 20 elements in the sequence
                if(divi==20){
                    printf("Buzz and Fizz\n");
                    //reset the divisibility check iterator
                    divi=0;
                }
                else{
                    //check for 3s divisibility
                    if(div3[divi]){
                        printf("Buzz\n");
                    }
                    //check for 5s divisibility
                    else{
                        if(div5[divi]){
                            printf("Fizz\n");
                        }
                        //else print the number
                        else{
                            printf("%" PRIu64 "\n",fn);
                        }
                    }
                }
            }
        }
        //increment the divisibility check iterator
        divi++;
    }
}

int main() {
    fibbout(94);
    return 0;
}

