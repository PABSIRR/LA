# Mini Bomb Challenge

This repository contains a "bomb" challenge program commonly used in systems programming education. The program requires users to provide specific inputs to "defuse" the bomb and reveal a flag or secret message.
Here is the corresponding medium blog: https://medium.com/@skylarshi123/walking-through-assembly-23f22ad87110

## Overview

The bomb is a simple C program that prompts the user for inputs. If the correct inputs are provided, the bomb is "defused" and reveals the flag. If incorrect inputs are provided, the bomb "explodes" (terminates with an error message).

## Requirements

To work with this challenge, you'll need:

- Access to a Linux environment (preferably x86_64 architecture)
- GCC compiler
- Basic knowledge of command-line tools
- Optional: GDB (GNU Debugger) for analysis

## Getting Started

### Accessing the UCLA Linux Servers (for UCLA students)

If you're a UCLA student, you can access the Linux servers which provide the appropriate environment:

```bash
# Replace 'username' with your UCLA account username
ssh username@lnxsrv13.seas.ucla.edu
```

You'll be prompted for your password. Once logged in, you'll be in your home directory on the server.

### Transferring Files to the Server

If you've modified the bomb locally and need to transfer it to the server:

```bash
# From your local machine, not the server
# Replace 'username' with your UCLA account username
scp minibomb.c username@lnxsrv13.seas.ucla.edu:~
```

This command copies the minibomb.c file to your home directory on the server.

### Compiling the Bomb

To compile the bomb program, you have two options:

#### Option 1: Using the Makefile

The simplest way is to use the provided Makefile:

```bash
# Compile the program
make

# Clean up (remove compiled files)
make clean
```

#### Option 2: Compiling Manually

If you prefer to compile manually:

```bash
gcc minibomb.c -Wall -Wpedantic -Werror -O0 -fno-inline -fno-pie -std=c99 -o minibomb
```

This compiles the C file with specific flags:
- `-Wall -Wpedantic -Werror`: Enable strict warning and error checking
- `-O0`: Disable optimizations (makes the assembly output more predictable)
- `-fno-inline`: Prevent function inlining (makes the assembly easier to follow)
- `-fno-pie`: Disable position-independent executable (simplifies address references)
- `-std=c99`: Use C99 standard

### Running the Bomb

Once compiled, you can run the bomb with:

```bash
./minibomb
```

The program will prompt you for inputs. Be careful! Incorrect inputs will cause the bomb to "explode."

## Analyzing the Bomb

To solve the bomb, you'll need to analyze its behavior. Here are some helpful commands:

### Using objdump to Disassemble

```bash
objdump -d minibomb > minibomb_disassembly.txt
```

This command disassembles the compiled binary and saves the assembly code to a text file for analysis. It shows the machine code instructions that make up the program.

### Using GDB for Dynamic Analysis

GDB is a powerful debugger that allows you to run the program step-by-step:

```bash
# Start GDB with the minibomb program
gdb ./minibomb
```

Once in GDB, you can use these common commands:

```
# Set a breakpoint at the main function
(gdb) break main

# Start the program
(gdb) run

# Execute the next instruction (step into functions)
(gdb) step

# Execute the next instruction (step over functions)
(gdb) next

# Continue execution until the next breakpoint
(gdb) continue

# Examine memory at an address or variable
(gdb) x/s &secret  # View the secret string

# Print the value of a variable or expression
(gdb) print magic(1337133713370)

# Disassemble a function
(gdb) disassemble main

# Quit GDB
(gdb) quit
```

## Creating Your Own Challenge

To create your own bomb challenge, modify the `minibomb.c` file:

1. Change the `secret` string to your own password
2. Modify the `magic()` function to have different cases and return values
3. Change the condition in main (e.g., `if (magic(n) != 22)`) to match your modified function
4. Optionally, change the `flag.txt` contents or hardcode a different message

Example modification to make a simpler challenge:

```c
const char* secret = "password123\n";  // Changed password

int magic(long long n) {
    if (n == 42) return 100;           // Simplified magic function
    else return 0;
}

// In main()
if (magic(n) != 100) {                 // Changed expected value
    explode();
}
```

## How It Works Internally

The bomb challenge works by checking user inputs against expected values:

1. **Password Check**: The program reads a string from the user and compares it to a hardcoded `secret` string using `strcmp()`. If they don't match, the bomb "explodes."

2. **Number Check**: The program reads a number and passes it to the `magic()` function. This function has a switch statement with various cases that calculate a return value in different ways. Only specific input numbers will produce the expected return value (22 in the original code).

3. **Control Flow**: The `explode()` function is called when checks fail, terminating the program. The `defuse()` function is called when all checks pass, reading and displaying the flag.

The challenge is designed for reverse engineering education, requiring students to analyze the compiled binary to determine the correct inputs rather than simply reading the source code.

## Troubleshooting

- **Compilation Errors**: Ensure you have the necessary development tools installed.
  ```bash
  # On Ubuntu/Debian
  sudo apt-get update
  sudo apt-get install build-essential gdb
  ```

- **Architecture Issues**: If you need to compile for a specific architecture (e.g., 32-bit):
  ```bash
  # Install multilib support
  sudo apt-get install gcc-multilib
  
  # Compile with 32-bit flag
  gcc -m32 minibomb.c -o minibomb
  ```

- **Permission Denied**: If you can't execute the compiled bomb:
  ```bash
  chmod +x minibomb
  ```

## Notes

- This challenge is designed for educational purposes only.
- The compiled program is architecture-dependent, so it's best to compile it on the same type of system where you'll run it.
- The UCLA Linux servers are configured with the appropriate environments for this challenge.