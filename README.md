# 🧩 2048 – The Real Puzzle (SFML Edition)

A graphical implementation of the classic **2048 game** built in **C++ using SFML**. This project recreates the original sliding tile puzzle with an interactive UI where players combine numbers to reach the **2048 tile**.

---

## 🎮 Game Overview

**2048 – The Real Puzzle** is a single-player game played on a **4×4 grid**. The goal is to merge tiles with the same number until you reach **2048**.

After every move, a new tile (2) appears randomly on the board. The game ends when no valid moves are left.

---

## ✨ Features

- 🟦 4×4 grid-based gameplay  
- 🎨 Graphical UI built with **SFML**  
- 🔄 Smooth tile movement (W, A, S, D controls)  
- ➕ Automatic tile merging system  
- 💾 Save and resume game using file handling (`2048.txt`)  
- 🎯 Win condition (reach 2048 tile)  
- ❌ Game over detection  
- 📜 Instructions menu  

---

## 🎮 Controls

| Key | Action |
|-----|--------|
| W   | Move Up |
| A   | Move Left |
| S   | Move Down |
| D   | Move Right |
| 0   | Save Game & Return to Menu |

---

## 💾 Save / Load Feature
Game state is saved in: 2048.txt
Select "Resume Last Game" to continue from saved progress
Select "Start New Game" to begin a fresh session
Allows seamless continuation without losing progress

---

## 🧠 Game Rules
- Use W, A, S, D to move tiles
- Tiles with the same value merge into one (e.g., 2 + 2 = 4)
- After each move, a new tile (2) appears randomly
- Reach 2048 to win the game
- Game ends when no valid moves are available

---

## 🏗️ Project Structure
- Game struct → Stores the 4×4 board
- displayboard() → Renders the board using SFML
- shift functions → Handle tile movement logic
- move functions → Manage merging of tiles
- newTile() → Generates a new tile randomly
- isGameWon() → Checks win condition (2048)
- isGameOver() → Checks if no moves remain
- File handling → Save/load game stat

---

## 🚀 Future Improvements
- 📊 Score tracking system
- ↩️ Undo last move feature
- 🎲 Improved random tile generation (2 & 4)
- ✨ Enhanced animations and transitions
- 🔊 Sound effects and UI enhancements

---
## 👨‍💻 Author

Muhammad Usman Khan
🔗 GitHub: https://github.com/Usman1dev
🔗 LinkedIn: https://www.linkedin.com/in/usman0310
---

## 📂 How to Run

### 1. Compile the program
Make sure **SFML is installed and configured**.

```bash
g++ main.cpp -o 2048 -lsfml-graphics -lsfml-window -lsfml-system
./2048

