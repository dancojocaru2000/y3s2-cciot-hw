# CCIoT Homework Lab 2

## Slide 12

### Problem

Try the following:

1. Create a vector of whatever type you like (minimum length of 10);
2. Print it’s content;
3. Erase the odd elements;
4. Replace the first element and the last element with another value;
5. Create a rule that erases the 5th element from the vector;
6. Use cppreference in the meantime ☺

### Solution

See [slide12.cpp](./slide12.cpp).

## Slide 13

### Problem

Try the same stuff with std::list, observe the differences.

### Solution

See [slide13.cpp](./slide13.cpp).

The difference observed is at line 38.
Because `std::list` has a bidirectional iterator, not a random access one, skipping 4 elements cannot be done.
Instead, I had to use `std::next` in order to advance the iterator 4 times separately in order to find the 5th element and erase it.
