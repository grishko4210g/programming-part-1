# Lab 01 — Setup env Report Template
 
---
**Course:** Programming, Part 1  
**Institution:** NTU KhPI, Kharkiv, Ukraine  
**Student:**   Arina Hryshko
**Date:** Septemper 09,2025  
 
---
 
## Task Description
 
1. Setup WSL or VirtualBox or HyperV
2. Setup VS code
3. Using the package manager install gcc/g++, clang/clang++, gdb, lldb, make, cmake
4. Write a report and attach it to this task
 
 ## Report
 The goal of this lab is to setting up a C/C++ development enviroment on Linux(or WSL) for further programming task
 
In this lab, I completed the following tasks: Setup WSL, Setup VS code, install gcc/g++, clang/clang++, gdb, lldb, make, cmake

## Lab Instructions

Use the following commands to build, test, and analyze the project.
 
### How to Build
 In this lab, I completed the following tasks:
 1. **Set up WSL**
   I installed WSL (Windows Subsystem for Linux) on Windows 10 Home using instructions from the Microsoft website:

```bash
wsl --install
```
 After installation, I chose the Ubuntu distribution.

 2. **Installed Visual Studio Code**
   I downloaded and installed Visual Studio Code from the [official website](https://code.visualstudio.com/download).
   I installed the "remote - WSL" extensionto workwith code inside WSL.

   3. **Installed required tools using the package manager**

   In the Ubuntu terminal, I wrote these commands:

 ```bash
   sudo apt update
   sudo apt install build-essential gdb clang lldb make cmake -y
   ```

   4. **Checked the installed**

  ```bash
    gcc --version
    g++ --version
    clang --version
    clang++ --version
    gdb --version
    lldb --version
    make --version
    cmake --version
  ```


### Observations and Conclusion
 
>As a result of this lab work, I created a modern environment for C/C++ development based on WSL and Ubuntu. All the necessary tools were successfully installed and are ready to be used in future lab work.
 
 
 
---

