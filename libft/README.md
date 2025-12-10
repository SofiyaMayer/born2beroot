*This project has been created as part of the 42 curriculum by someyer.*

# Description
The goal of this project is to create a **static library** containing **custom implementations** of useful functions, which can be reused in future projects.

While some of these functions already exist in the standard C library (libc), the purpose of this project is to implement them manually to gain a deeper understanding of how they work. Most of them can be read in manual using **man** command.


This repository includes:

- **.c files:** Implementations of individual functions.

- **.h header file:** Function declarations for use in other programs.

- **Makefile:** Automates compilation of the project.

# Instructions

## Compile the Library
The library is compiled using shell command:
```console
make all
```
It will create libft.a file, using command:
```console
ar rcs libft.a *.o 
```

## Cleaning project files
- Remove object files:
```console
make clean
```
- Remove object files and libft.a library
```console
make fclean
```

## Using the Library in other projects

- Include the header file in your .c file
```c
#include "libft.h";
```
- Compile your .c file e.g. with command like this:
```console
cc -Wall -Wextra -Werror yourprogram.c -L. -lft
```

# Resources

- Manual, that contains official libc functions

- pdf file attached in the project also contains some descriptions for other functions, that are not part of libc

- logic behind the functions came out from my head, but testing was a bit challenging, because I forget about a lot of things.

- AI was useful for paraphrasing my baby-like sentences in English, so it'll not appear too ugly for my peers :)