
# Simple Shell

## 📖 Project Description

This project consists of building a simple UNIX command-line interpreter (shell) in the C programming language. Its main goal is to simulate essential functionalities of a basic shell, allowing users to execute commands directly from the terminal.

---

## 🚀 Installation

To download and compile this shell:

```bash
git clone https://github.com/yourusername/holbertonschool-simple_shell.git
cd holbertonschool-simple_shell
make
```


## ⚙️ Usage

Launch the shell by running:

```bash
./hsh
```

Sample usage:

```bash
#cisfun$ ls
#cisfun$ /bin/ls -l
#cisfun$ env
#cisfun$ exit
```


## ✅ Features

- [x] Interactive shell prompt (`#cisfun$`)
- [x] Execute commands using `execve()`
- [x] Command search using the `PATH` environment variable
- [x] Built-in commands:
  - `exit`: exits the shell
  - `env`: displays the current environment variables
- [x] Input parsing using `getline()` and `strtok()`
- [x] Process management with `fork()` and `wait()`
- [x] Dynamic memory handling with `malloc()` and `free()`
- [x] Error handling for invalid commands
- [x] Modular and well-commented codebase

---

## 📂 File Structure

```
.
├── AUTHORS              # List of contributors
├── execute.c            # Command execution logic
├── find_in_path.c       # Resolve commands using PATH
├── functions.c          # Core shell logic (input, parsing, environment)
├── main.c               # Program entry point
├── shell.h              # Unified header file
├── utils.c              # Helper functions
├── hsh                  # Compiled executable
├── Makefile             # Build instructions
└── README.md            # Project documentation
```

---

## 🧠 Learning Objectives

- Master the use of system calls (`execve`, `fork`, `wait`, etc.)
- Understand how environment variables and paths are managed
- Improve skills in dynamic memory management
- Practice modular programming and clean code structure
- Reinforce teamwork, Git/GitHub workflows, and debugging

---

## 📊 Summary of Accomplishments

In this project, we built a UNIX-like command-line interpreter in C from scratch. The goal was to understand how standard shells like `sh` or `bash` work internally by implementing core features manually.

### Key achievements:

- Implemented an interactive shell prompt (`#cisfun$`)
- Read user input using `getline()` and tokenized it
- Executed commands using `execve()` after resolving them via `PATH`
- Implemented built-in commands: `exit` and `env`
- Managed child processes with `fork()` and `wait()`
- Displayed meaningful error messages for invalid commands
- Structured the project into modular, maintainable files
- Followed Holberton's Betty coding style

---

## 👨‍💻 Authors

See the [AUTHORS](./AUTHORS) file for full list of contributors.

---

## 📎 License

This project is part of the Holberton School curriculum. For educational purposes only.
