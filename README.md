# ECE528_HW1

## Section I: Review Questions

### 1.
a. A compiler translates the entire source program into machine code before it runs. An interpreter reads and executes the program line by line.

b. By default, main() returns an int status code, it implicitly returns 0. 

### 2.
Header fi;es in C are text files with a .h extension that contain declarations for functions, data types, macros, and constants.

The purpose of the #include directive is to tell the preprocessor to insert the entire contents of a specified file into the source code before compilation takes place

### 3.
A declaration tells the compiler the function's name, return type, and parameter types. A definition provides the function body.

```c

int add(int a, int b) // declaration


int add(int a, int b) // definition
{
    return a + b;
}
```
The return statment ends a function and sends a value back to the caller. A function can have more than one return statement, but only one will execute

### 4.
Type casting converts a value from one data type to another. Implicit casting is done automatically by the compiler. Explicit casting is requested by the programmer with the (type) operator. Casting double to int truncates the fractional part (it does not round).

```c
int add_doubles(double a, double b)
{
    return (int)(a + b); // explicit cast from double to int
}
```

### 5.
A local variable is declared inside a function or block. It is only visible within that scope and  is created when the block is entered and destroyed when it exits. A global variable is declared outside all functions. It is visible to every function in the file and exists for the entire program run.

```c
int global_count = 0; // global

void increment(void)
{
    int local_temp = 5; // local
    global_count += local_temp;
}
```

### 6.

```c
char name1[] = "Hello"; // size 6 (includes '\0')
```

The null terminator '\0'  marks the end of the string. 

### 7.
A pointer is a variable that stores the memory address of another variable. It is declared with *.

To pass a pointer to a function, declare the parameter as a pointer type and pass an address (using `&` or an existing pointer):


Advantages over passing by value:
- The function can modify the caller's variable 
- It avoids copying large data, saving time and memory. Only the address is copied.
- Allows a function to return multiple results through output parameters.
- Arrays are passed as pointers, and pointers are how hardware registers/memory are accessed in embedded systems.

### 8.
- & (address-of operator): returns the memory address of a variable. 
- `*` : accesses the value stored at the address held by a pointer. 

### 9.
- while: checks the condition before each iteration, so the body may execute zero times.
- do...while: executes the body first and checks the condition after, so the body always executes at least once. It ends with a semicolon.

### 10.
- break immediately exits the innermost loop and execution continues with the statement after it.
- continue skips the rest of the current iteration and jumps to the next iteration. The loop itself is not terminated.

### 11.
Bitwise operators work on the individual bits of integer operands:
- & AND: bit is 1 only if both bits are 1 (Clear and Check)
- | OR: bit is 1 if either bit is 1 (Set)
- ^ XOR: bit is 1 if the bits differ (Toggle)
- ~ NOT: inverts every bit (Clear)
- << left shift: shifts bits left (fills with 0s; multiplies by 2 per shift)
- `>>` right shift: shifts bits right (divides by 2 per shift)

### 12.
PxSEL0 and PxSEL1 are the port function-select registers. For each pin, the corresponding bit in PxSEL0 and PxSEL1 together selects the pin's function: SEL1:SEL0 = 00 is general-purpose I/O (GPIO), while 01, 10, and 11 select the primary, secondary, and tertiary module functions (UART, SPI, timers, etc.).

To select GPIO for P1.0 and P1.7:

```c
P1->SEL0 &= ~0x81; // clear bit 0 and bit 7 in SEL0
P1->SEL1 &= ~0x81; // clear bit 0 and bit 7 in SEL1
```

### 13.
Mask for P1.1 and P1.4: 0x12 (bits 1 and 4). For pull-ups: REN = 1 and OUT = 1.

```c
void P1_1_and_P1_4_Init(void)
{
    // GPIO function
    P1->SEL0 &= ~0x12;
    P1->SEL1 &= ~0x12;

    // Inputs
    P1->DIR &= ~0x12;

    // Enable resistors and select pull-up
    P1->REN |= 0x12;
    P1->OUT |= 0x12;
}
```

### 14.
Masks: P3.1 and P3.6 → 0x42; P5.0 and P5.4 → 0x11. For pull-downs: REN = 1 and OUT = 0.

```c
void Buttons_Init(void)
{
    // GPIO function
    P3->SEL0 &= ~0x42;
    P3->SEL1 &= ~0x42;
    P5->SEL0 &= ~0x11;
    P5->SEL1 &= ~0x11;

    // Inputs
    P3->DIR &= ~0x42;
    P5->DIR &= ~0x11;

    // Enable resistors and select pull-down
    P3->REN |= 0x42;
    P5->REN |= 0x11;
    P3->OUT &= ~0x42;
    P5->OUT &= ~0x11;
}
```

### 15.
Mask for P7.0–P7.7: 0xFF.

```c
void LEDs_Init(void)
{
    // GPIO function
    P7->SEL0 &= ~0xFF;
    P7->SEL1 &= ~0xFF;

    // Outputs
    P7->DIR |= 0xFF;

    // Initialize to zero (LEDs off)
    P7->OUT &= ~0xFF;
}
```
