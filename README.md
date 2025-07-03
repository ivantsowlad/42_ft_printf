# 42_ft_printf

This project is part of the 42Prague curriculum.

## Overview

**ft_printf** is a custom implementation of the standard C `printf` function. The goal of this project is to create a function capable of formatted output, supporting several commonly used format specifiers. This project deepens understanding of variadic functions, string formatting, and low-level output in C.

## Features

- Reimplementation of the core behavior of the C `printf` function
- Handles variable argument lists using `stdarg.h`
- Supports the following format specifiers:
  - `%c` : Character
  - `%s` : String
  - `%p` : Pointer address
  - `%d`, `%i` : Signed decimal integer
  - `%u` : Unsigned decimal integer
  - `%x`, `%X` : Unsigned hexadecimal (lower/upper case)
  - `%%` : Literal percent sign
- Adheres to the 42 coding standards

## Directory Structure

```
.
├── *.c
├── *.h
└── Makefile
```

## How to Use

1. **Clone the repository:**
    ```bash
    git clone https://github.com/ivantsowlad/ft_printf.git
    cd ft_printf
    ```

2. **Build the library:**
    ```bash
    make
    ```
   This will generate the `libftprintf.a` static library file.

3. **Include in your project:**
   - Add `libftprintf.a` to your project's linking step.
   - Include `ft_printf.h` in your source files.

    ```c
    #include "ft_printf.h"
    ```

4. **Clean built files:**
    ```bash
    make clean      # Removes object files
    make fclean     # Removes object files and libftprintf.a
    make re         # Rebuilds the library
    ```

## Example

```c
#include "libftprintf.h"

int	main(void)
{
	int	x;

	x = ft_printf("Hello %s! Number: %d, Hex: %x, \
Pointer: %p, Char: %c, %%\n", "world", 42, 255, (void *)0x1234, 'A');
	printf("ft_printf returned: %d\n", x);
	printf("Hello %s! Number: %d, Hex: %x, Pointer: %p, \
Char: %c, %%\n", "world", 42, 255, (void *)0x1234, 'A');
	return (0);
}
```

Compile and link with the library:
```bash
gcc main.c -L. -lftprintf
```

## Requirements

- GCC or compatible C compiler
- Make

## Notes

- The implementation does not use any functions from the C standard library except `write`, `malloc`, and `free`, as per 42 project requirements.
- All functions are prefixed with `ft_` to avoid conflicts.

## License

This project is part of the 42Prague curriculum and is intended for educational use.

## Author

- [ivantsowlad](https://github.com/ivantsowlad)
