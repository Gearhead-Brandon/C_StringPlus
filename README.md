# String+

Implementation of the `string.h` library with additions.

## Contents
1. [Introduction](#introduction)
2. [Requirements](#requirements)
    - [Part 1: Implementation of the string.h library functions](#part-1-implementation-of-the-stringh-library-functions)
    - [Part 2: Partial implementation of the `sprintf` function](#part-2-partial-implementation-of-the-sprintf-function)
    - [Part 3: Bonus - Implementation of some format modifiers of the `sprintf` function](#part-3-bonus-implementation-of-some-format-modifiers-of-the-sprintf-function)
    - [Part 4: Bonus - Implementation of special string processing functions](#part-4-bonus-implementation-of-special-string-processing-functions)

## Introduction

In this project, you will develop your own implementation of the `string.h` library in C, with some additional functions such as `sprintf` and special string processing functions. The library should implement common string operations and some of the functions used in the C programming language's `string.h` header.

## Requirements

### Part 1. Implementation of the `string.h` Library Functions
- Implement the following functions from `string.h`:
  - Functions related to memory operations (e.g., `memcpy`, `memset`, etc.)
  - String manipulation functions (e.g., `strlen`, `strcat`, `strncpy`, etc.)
  - Functions for searching within strings (e.g., `strchr`, `strstr`, etc.)
  - Error handling with `strerror`, which needs to handle platform-specific errors
- The library must be developed using the C11 standard, with strict adherence to POSIX.1-2017 standards and Google style guide.
- The library should be static (`s21_string.a`) and include appropriate header files (`s21_string.h`).
- Write unit tests to ensure that each function works correctly, covering at least 80% of each function.
- Create a `Makefile` that builds the library, tests, and generates coverage reports using `gcov`.

### Part 2. Partial Implementation of the `sprintf` Function
- Implement a partial version of the `sprintf` function to format strings with the following specifiers:
  - `c`, `d`, `f`, `s`, `u`, `%`
  - Flags: `-`, `+`, ` (space)`
  - Width description: `(number)`
  - Precision description: `.(number)`
  - Length description: `h`, `l`

### Part 3. Bonus - Implementation of Some Format Modifiers of the `sprintf` Function
- Extend your implementation of `sprintf` by adding the following additional format specifiers and modifiers:
  - Specifiers: `g`, `G`, `e`, `E`, `x`, `X`, `o`, `p`
  - Flags: `#`, `0`
  - Width description: `*`
  - Precision description: `.*`
  - Length description: `L`

### Part 4. Bonus - Implementation of Special String Processing Functions
- Implement special string processing functions as follows:
  - `to_upper(const char *str)` – Returns a new string converted to uppercase.
  - `to_lower(const char *str)` – Returns a new string converted to lowercase.
  - `insert(const char *src, const char *str, size_t start_index)` – Returns a new string with `str` inserted at `start_index` in `src`.
  - `trim(const char *src, const char *trim_chars)` – Returns a new string with leading and trailing characters from `trim_chars` removed from `src`.

## General Requirements
- The implementation must not use any system libraries or predefined string libraries (except for the standard `string.h` functions used in the tests).
- Unit tests must compare your implementations with the standard library's behavior and test edge cases.
- Provide a Makefile to automate the building process and running of tests.
<!--  -->
