# Running C++ Code on Mac and Windows

This README file provides instructions on how to compile and run C++ code on both Mac and Windows operating systems.

## Prerequisites

- **Mac**:
  - Xcode Command Line Tools (for compiling C++ code)
  - Terminal (for running commands)

- **Windows**:
  - MinGW or Visual Studio (for compiling C++ code)
  - Command Prompt or PowerShell (for running commands)

## Steps

1- Clone the repository:
git clone https://github.com/MUHAMMEDMAME/major_assignment.git
cd major_assignment

2. **Compile the Code**:
   - **Mac**:
     ```
     g++ -std=c++11 -o problem1 problem1.cpp
     ```
   - **Windows** (using MinGW):
     ```
     g++ -std=c++11  -o problem1.exe problem1.cpp
     ```
   - **Windows** (using Visual Studio):
     ```
     cl problem1.cpp
     ```

3. **Run the Executable**:
   - **Mac**:
     ```
     ./problem1
     ```
   - **Windows**:
     ```
     problem1.exe
     ```





  




