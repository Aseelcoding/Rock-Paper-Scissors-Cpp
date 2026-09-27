# Rock Paper Scissors — C++

A classic **Rock Paper Scissors** console game written in C++. The player competes against a randomly selected computer choice over a configurable number of rounds.

## Project Status

**Core gameplay is implemented and functional.** The project focuses on control flow, enums, functions, randomization, input validation, and basic game-state tracking.

## Feature Status

### Implemented — Working

- **Rock, Paper, Scissors choices**
- **Random computer selection**
- **Configurable rounds** from 1 to 10.
- **Round-by-round winner detection**
- **Player win counter**
- **Computer win counter**
- **Draw counter**
- **Final game result**
- **Play-again option**
- **Console color feedback**
- **Basic input range validation**

### Partially Implemented / Needs Refinement

- **Input validation** — Numeric range validation exists, but non-numeric input handling can be improved.
- **Console presentation** — The UI uses Windows console commands for screen clearing and colors.
- **Game state** — The current implementation keeps statistics for the active game session only.

### Planned — Coming Soon

The following improvements are **not currently implemented** and are planned for future updates:

- Persistent high scores.
- Player names and profiles.
- Game history.
- Best-of-series mode.
- Stronger input handling.
- Cross-platform console support.
- Cleaner UI and output formatting.
- Automated tests.

## Game Flow

```text
Start Game
   │
   ▼
Choose Number of Rounds
   │
   ▼
Player Chooses Rock / Paper / Scissors
   │
   ▼
Computer Generates Random Choice
   │
   ▼
Determine Round Winner
   │
   ▼
Update Score
   │
   ▼
Repeat Until All Rounds Finish
   │
   ▼
Display Final Winner
   │
   ▼
Play Again?
```

## Technologies & Concepts

- **C++**
- Enumerations
- Structures
- Functions
- Random number generation
- Loops and conditionals
- Input validation
- Console applications

## Getting Started

1. Open `main.cpp` in a C++ development environment.
2. Compile it as a console application.
3. Run the executable.
4. Choose the number of rounds and play.

> **Note:** The current implementation uses Windows console commands such as `system("cls")` and `system("color")`, so Windows is the intended environment.

## Project Structure

```text
Rock-Paper-Scissors-Cpp/
└── main.cpp
```

## Learning Objectives

This project demonstrates:

- Using enums to represent game states.
- Separating game logic into functions.
- Generating random computer choices.
- Tracking results across multiple rounds.
- Building a simple interactive console game.

## Roadmap

Future updates will focus on stronger input handling, persistent statistics, richer game modes, and improved cross-platform support.

## Author

**Aseelcoding**
