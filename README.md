# Swift-Navigation-Application-Question

The code quickly produces the desired output and operates correctly up until the 93rd Fibonacci number, at which point subsequent Fibonacci numbers exceed the maximum data range for unsigned 64 bit integers. It is possible to extend functionality by implementing arbitrary-precision arithmetic.

Rather than implementing a naive, probabilistic, or fast deterministic algorithm for testing primality, the program compares the index to the indicies of all 49 known Fibonacci primes. Since the program is not designed to work with extremely large numbers (i.e discovering yet unknown primes), significant run time savings were achieved without losing any functionality.

Likewise, the program doesn't make use of any modulo operations to test if values are divisible by 3 or by 5. It can be shown that every 4th number in the series is divisible by 3, and every 5th number is divisible by 5. By testing against a boolean array, divisibility can be determined without using undue operations.

Finally the program outputs "Buzz and Fizz" when the output is divisible by both 3 and 5.
