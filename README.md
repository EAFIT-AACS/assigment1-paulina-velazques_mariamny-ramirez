[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/95BWY5mA)


Student Information
--

Student Name: Paulina Velásquez Londoño & Mariamny Del Valle Ramírez Telles

Class Number: 7309

Environment and Tools

Operating System:
--
Any system supporting C++ compilation

Programming Language: 
--
C++

Tools Used:
--
CLion, OnlineGDB

Instructions for Running the Implementation
--

Compiling the Code
--

If you are using a C++ compiler like CLion, execute the following command in the terminal:
--
g++ main.cpp -o test
--
This will generate an executable named test.

Running the Program
--
./test
--

This will start the program and prompt the user for input.

Entering Data
--

Follow these instructions when prompted by the program:

Total number of states: Enter an integer.

Number of final states: Enter an integer.

Final states: Enter the final states separated by spaces.

Alphabet symbols: Enter the symbols separated by spaces (e.g., a b).

Transitions: For each state, enter the destination state corresponding to each symbol in the alphabet.

Viewing Results
--

The program will print the entered transitions for verification.

It will then display the equivalent states found.

Explanation of the Algorithm
--

1. Data Input

The program requests:

The number of states in the automaton.

The number and list of final states.

The symbols in the alphabet.

The transition states for each input symbol.

2. Construction of the Equivalence Table

A matrix table[states][states] is initialized:

table[i][j] = false indicates that states i and j might be equivalent.

table[i][j] = true indicates that i and j are distinguishable.

3. Marking Distinguishable States

Initially, the algorithm marks pairs of states as different if:

One is a final state, and the other is not.

4. Iterative Refinement

The algorithm iterates through all pairs (i, j), checking if:

For some symbol s, the states transitions[i][s] and transitions[j][s] are already marked as different.

If so, table[i][j] is marked as true (states i and j are distinguishable).

The process repeats until no further changes occur in the table.

5. Identifying Equivalent States

The algorithm scans all pairs (i, j) and determines that i and j are equivalent if table[i][j] == false.

6. Output Results

The program prints the pairs of equivalent states found.
![image](https://github.com/user-attachments/assets/9f5a2767-d34e-4d46-a77c-b89e393cde74)
