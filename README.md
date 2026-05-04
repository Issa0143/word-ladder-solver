## Word Ladder Solver

## Author

    Josue Aguilar Mejia

## Description
- This project is a C++ command-line application that finds the shortest transformation sequence between two words, where each step changes one letter and must form a valid word.

- This project was originally inspired by a final project from a community college course. I rebuilt and improved to demonstrate stronger coding practices, cleaner structure, and algorithmic problem-solving using Breadth First Search (BFS).

## Example

    Start word: hit
    End word: cog

    Output:
    hit hot dot dog cog

## Features
- Finds word ladder paths using BFS 
- Reads valid words from a `dictionary.txt` file
- Uses C++ STL data structures such as `queue`, `vector`, and `unordered_set`
- Validates that input words are the same length
- Rebuilt and improve from an earlier project to demonstrate growth in programing skills

## How to Run

bash:

g++ -std=c++17 main.cpp -o wordladder
./wordladder