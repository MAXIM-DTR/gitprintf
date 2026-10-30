*This project has been created as part of the 42 curriculum by [your_login].*

# ft_printf

## Description

Reimplementation of the standard C `printf()` function as a static library.
Handles the most common format specifiers using variadic arguments (`va_list`).
No buffer management — each character is written directly via `write(2)`.

Supported conversions:

| Specifier | Output |
|-----------|--------|
| `%c` | Single character |
| `%s` | String (`(null)` if NULL) |
| `%p` | Pointer address in hex with `0x` prefix (`(nil)` if NULL) |
| `%d` / `%i` | Signed decimal integer |
| `%u` | Unsigned decimal integer |
| `%x` | Unsigned hex, lowercase |
| `%X` | Unsigned hex, uppercase |
| `%%` | Literal percent sign |

## Instructions

**Compile the library:**
```bash
make
```

**Link with your project:**
```bash
cc main.c -L. -lftprintf -o program
```

**Include in source:**
```c
#include "ft_printf.h"
```

**Clean:**
```bash
make clean    # remove object files
make fclean   # remove object files and library
make re       # full rebuild
```

**Requirements:** `cc`, `ar`, standard POSIX environment.

## Algorithm and Data Structure

**Parsing loop** — `ft_printf` iterates over the format string character by character using an index. When it encounters `%` followed by a non-null character, it dispatches to a handler; otherwise it writes the character directly.

**Dispatch table** — `ft_dispatch` uses a chain of `if` checks on the conversion character. This is the simplest structure for 8 specifiers; a function pointer table would be an alternative but adds complexity for no real gain at this scale.

**Recursive digit output** — `ft_putunbr`, `ft_putnbr`, and `ft_puthex` use recursion to print digits in the correct (most-significant-first) order without needing a temporary buffer. Recursion depth is bounded by the number of digits (max 20 for 64-bit values).

**INT_MIN handling** — `ft_putnbr` casts `n` to `long` before negating to avoid signed overflow on `INT_MIN` (-2147483648), then passes the result to `ft_putunbr` as `unsigned int`.

**64-bit pointers** — `ft_puthex` takes `unsigned long` to correctly print 64-bit pointer values from `%p`.

## Resources

- `man 3 printf` — official specification
- `man 3 stdarg` — variadic arguments (`va_start`, `va_arg`, `va_end`)
- [cppreference — printf](https://en.cppreference.com/w/c/io/fprintf)
- [42 Norm v3](https://github.com/42School/norminette) — coding standard enforced at 42

**AI usage:** AI (Claude) was used to generate the initial implementation structure and all source files. The algorithm, design choices, and norm compliance were reviewed manually. AI was not used during the learning/understanding phase — this README documents what the code does and why.
