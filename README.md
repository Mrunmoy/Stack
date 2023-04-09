# Stack Library 
![Test Status](https://github.com//Mrunmoy/Stack/workflows/BuildAndTest/badge.svg?branch=master)



This project provides a simple stack library written in C, along with a set of unit tests written in C++ using the Google Test framework. The library provides basic stack functionality, including the ability to create and destroy a stack, push and pop elements onto and off of the stack, and check if the stack is empty.

## Installation

To use the library, simply clone the repository and include the `stack.h` header file in your C project.

## Usage

Here is an example of how to use the stack library:

```c
#include <stdio.h>
#include "stack.h"

int main() {
    Stack_t *stack = stack_create(10);
    int data1 = 42, data2 = 84;
    stack_push(stack, &data1);
    stack_push(stack, &data2);
    printf("%d\n", *(int *)stack_pop(stack)); // prints 84
    printf("%d\n", *(int *)stack_peek(stack)); // prints 42
    stack_destroy(stack);
    return 0;
}
```

## Building the Project

To build the project, simply clone the repository and run the build script:

```sh
git clone git@github.com:Mrunmoy/Stack.git
cd Stack
```

## Building Shared and Static Versions of the Library
To build the shared version of the library, run the following command from the project root directory:
```
./build.sh --static --all
OR
./build.sh --shared --all
```
This will generate the stack/static library under ./build/main/lib


Running the Tests
To run the unit tests, simply execute the test executable:
```
./build.sh --static --test
OR
./build.sh --shared --test
```
This will run all of the unit tests and output the results to the console and also run code coverage.

## Code Coverage [![Coverage Badge](./coverage.svg)](./coverage.svg)
Coverage report is generated under build/coverage_report/index.html

## API
The stack library provides the following API:

Stack structure
```
typedef struct Stack_t {
    void **data;
    int size;
    int top;
} Stack_t;
```

APIs are:

- stack_create - Creates a new stack with the given size.
```Stack_t *stack_create(int size);```

- stack_push - Pushes the given data onto the top of the stack.
```int stack_push(Stack_t *stack, void *data);```

- stack_pop - Pops the top element off of the stack and returns it.
```void *stack_pop(Stack_t *stack);```

- stack_is_empty - Returns 1 if the stack is empty, 0 otherwise.
```int stack_is_empty(Stack_t *stack);```

- stack_peek - Returns the top element on the stack without popping it off.
```void *stack_peek(Stack_t *stack);```

- stack_destroy - Destroys the given stack and frees all associated memory.
```void stack_destroy(Stack_t *stack);```

## Contributing
Contributions are welcome! Please feel free to submit a pull request.

## License
This project is licensed under the MIT License - see the LICENSE file for details.
