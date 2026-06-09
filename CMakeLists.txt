cmake_minimum_required(VERSION 3.10)
project(CodeAlpha_Projects)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Task 1: CGPA Calculator
add_executable(cgpa_calculator task1_cgpa_calculator.cpp)

# Task 2: Login Registration
add_executable(login_registration task2_login_registration.cpp)

# Task 3: Sudoku Solver
add_executable(sudoku_solver task3_sudoku_solver.cpp)

# Task 4: Banking System
add_executable(banking_system task4_banking_system.cpp)
