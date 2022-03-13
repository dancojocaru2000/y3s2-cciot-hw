# CCIoT Homework Lab 1

## Slide 11

### Problem

```cpp
class Human
{
public:
    Human();
    ~Human();
    std::string name;
    int age;
};
```

Try this:

1. Create 4 humans.
2. Give them names and ages.
3. Retrieve the data from all humans and print it to the screen.
4. Print the data for the youngest human.
5. Print all humans’ names in descending order by their names.

### Solution

See [slide11.cpp](./slide11.cpp).

## Slide 13

### Problem

```cpp
class Human
{
public:
    Human();
    ~Human();
private:
    std::string name;
    int age;
};
```

Try this:

1. Try to retrieve the data from all humans and print it to the screen.
2. Try to find a workaround for the errors (if you don’t see any errors you’re doing something wrong).

### Solution

1. Because the `name` and `age` fields are private, they cannot be accessed.
2. A solution would be creating getters for them:

```cpp
class Human
{
    ...
public:
    const std::string& getName();
    const int& getAge();
};
```

