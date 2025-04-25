# Simple Shell

## Project Description

This project consists of building a simple UNIX command-line interpreter (shell) in the C programming language. Its main goal is to simulate essential functionalities of a basic shell, allowing users to execute commands directly from the terminal.

## Main Features

- Displays an **interactive prompt** to receive user commands.
- Reads user input using `getline()`.
- Tokenizes the input line into command and arguments.
- Resolves command paths using the `PATH` environment variable.
- Creates child processes with `fork()` and executes commands with `execve()`.
- Waits for child processes to finish using `wait()`.
- Implements the **built-in** commands: `exit` (to exit the shell) and `env` (to print environment variables).
- Basic error handling, including printing messages when a command is not found.

## Learning Objectives

This project reinforces knowledge about:

- Low-level programming in C.
- Process management and system calls.
- Memory handling with `malloc` and `free`.
- String manipulation and array handling.
- Modular program structure and file separation.

---

This shell was built to meet the requirements of the "Simple Shell" project at Holberton School.


