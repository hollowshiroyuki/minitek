# LibHSY

This is my version of the Epitech `libmy` with custom functions and prefix.

All the commands needs to be prefixed with `hsy_`.

As the standard `libc` is prohibited at Epitech, the depencies functions needs to be prefixed as well. (Except: `write`, `malloc`, `free`)

## List of functions

#### Display Functions

| Function Name | Function Parameters            | Return Value                         | Description                                                       | Dependencies      |
| ------------- | ------------------------------ | ------------------------------------ | ----------------------------------------------------------------- | ----------------- |
| `fd_putchar`  | (`int` fd, `char` c)           | Void                                 | Write a single char in given file descriptor.                     | `write`           |
| `putchar`     | (`char` c)                     | Void                                 | Write a single char in STDOUT.                                    | `fd_putchar`      |
| `fd_putstr`   | (`int` fd, `char const *` str) | (`ssize_t`) Number of written bytes. | Write a null byte terminated string in the given file descriptor. | `write`, `strlen` |
| `putstr`      | (`char const *` str)           | (`ssize_t`) Number of written bytes. | Write a null byte terminated string in STDOUT.                    | `fd_putstr`       |
| `fd_putnbr`   | (`int` fd, `int` nb)           | (`ssize_t`) Number of written bytes. | Write a number in the given file descriptor.                      | `fd_putchar`      |
| `putnbr`      | (`int` nb)                     | (`ssize_t`) Number of written bytes. | Write a number in STDOUT.                                         | `fd_putnbr`       |

#### Strings Functions

| Function Name | Function Parameters  | Return Value                      | Description                                                  | Dependencies |
| ------------- | -------------------- | --------------------------------- | ------------------------------------------------------------ | ------------ |
| `strlen`      | (`char const *` str) | (`size_t` ) Length of the string. | Return the number of bytes of a null byte terminated string. | None         |


