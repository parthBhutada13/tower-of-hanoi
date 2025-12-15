# tower-of-hanoi

## Project Overview

This project implements an interactive console-based solution to the classic Tower of Hanoi mathematical puzzle using fundamental data structures in C. The implementation focuses on demonstrating stack operations, recursive algorithm principles, and clean visual representation while providing an engaging user experience through ASCII-based visualization.

The study evaluates algorithmic efficiency, data structure selection, and user interaction design for educational and analytical purposes.

## Problem Statement

The Tower of Hanoi presents a well-known algorithmic challenge involving moving disks between rods under specific constraints. Traditional implementations often focus solely on the recursive solution without providing interactive visualization or educational value. This project addresses the challenge of creating an interactive, visually clear implementation that demonstrates both the mathematical principles and practical data structure applications while maintaining optimal performance.

## System Architecture

### Core Components

* **Data Representation**: 2D integer array modeling three rods with stack semantics
* **Visual Engine**: ASCII-based proportional disk rendering system
* **Game Logic**: Move validation and state management
* **User Interface**: Interactive console-based input system

### Technical Specifications

* **Maximum Disks**: 5 (configurable via `MAX` constant)
* **Rods**: 3 (fixed mathematical requirement)
* **Minimum Moves**: 2ⁿ - 1 (mathematical optimal)
* **Space Complexity**: O(n) for disk storage
* **Time Complexity**: O(2ⁿ) for optimal solution

## Data Structures and Implementation

### Primary Data Structures

* **2D Integer Array**: `int rods[RODS][MAX]`
  * Represents the three rods as stack-based structures
  * Provides O(1) access to top elements
  * Enables efficient move operations

* **Integer Array**: `int top[RODS]`
  * Stack pointers tracking current height of each rod
  * Enables constant-time push/pop operations


## Algorithmic Implementation

### Core Algorithms

1. **Initialize Function**
   * Sets up initial configuration with all disks on first rod
   * Implements stack initialization protocol

2. **Move Validation Algorithm**
   * Disk existence verification using linear search
   * Constraint checking (no larger on smaller)
   * State update with atomic push/pop operations

3. **Visualization Algorithm**
   * Proportional disk width calculation: `diskWidth = size * 2`
   * Centering logic: `padding = (BASE_WIDTH - diskWidth) / 2`
   * Rod state traversal for display generation

### Mathematical Foundation

* **Optimal Move Count**: Proven minimum of 2ⁿ - 1 moves
* **Recursive Solution**: Theoretically implemented through user interaction
* **State Space**: 3ⁿ possible configurations with constraints

## User Interface Design

### Visual Components

* **Proportional Disk Representation**: Width scales with disk size
* **Centered Display**: Consistent formatting regardless of disk count
* **State Information**: Clear rod labeling and move tracking

## Performance Analysis

### Time Complexity

| Operation | Complexity | Description |
|-----------|------------|-------------|
| Move Validation | O(n) worst-case | Disk search in all rods |
| State Update | O(1) | Array push/pop operations |
| Display Rendering | O(n) | Iterate through all disks |
| Complete Solution | O(2ⁿ) | Minimum moves required |

### Space Complexity

* **Fixed Allocation**: O(n) independent of move sequence
* **Stack Pointers**: Constant additional memory
* **Display Buffer**: Linear to disk count

## Results and Applications

### Educational Applications

1. **Data Structure Demonstration**: Clear stack implementation example
2. **Algorithm Visualization**: Step-by-step problem solving
3. **Mathematical Concepts**: Exponential growth demonstration
4. **Programming Fundamentals**: Input validation, state management, UI design

## Tools and Technologies

* **Programming Language**: C (ISO C11 standard)
* **Compiler**: GCC with `-std=c11 -lm` flags
* **Libraries**: Standard C Library (stdio.h, stdlib.h, math.h)
* **Development Environment**: Cross-platform compatible
* **Build System**: Simple Makefile or direct compilation

### Extension Points

1. **Difficulty Levels**: Adjustable disk count via configuration
2. **Auto-solver**: Recursive algorithm demonstration
3. **Move History**: Undo/redo functionality
4. **Performance Tracking**: Move count vs. optimal comparison

## Conclusion

This implementation successfully bridges the gap between mathematical algorithm and interactive educational tool. The array-based stack approach provides optimal performance for the problem constraints while maintaining clarity for learning purposes. The proportional visualization system offers intuitive understanding of disk relationships, and the complete validation system ensures mathematical correctness throughout interaction.

The project demonstrates effective application of fundamental data structures to classic computer science problems while providing extensible architecture for future enhancements. It serves as both a functional puzzle game and a comprehensive teaching resource for stack operations, algorithm design, and console-based UI development.
