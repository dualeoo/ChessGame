# ChessGame
## 1. Highlight
### 1.1 Object-oriented
- Structure is used to mimic class
- Function pointer is used to mimic methods
- Many things cannot be mimiced such as static field, extends
### 1.2 The AI
- The idea is to generate four random numbers randing from 0 to 7 inclusively. Check if these numbers constitute a valid move. If yes, make the move. If not, re-generate until find a valid move.
- The check-legal is adapted from Tuan (not merely copy)
- Plans to make this an independent project and develop a more "intelligent" AI.
### 1.3 The board
- The outline of the baord can be found in the file named "Board outline.png"
- Model using a two dimension array
- Player 1 is below. Col is labeled from A to H and Row is labeled from 1 to 8.
- Notice: The array, however, starts from index 0.
### 1.4 Serialization
## 2. What have been done?
### 2.1 Use case
### 2.2 Class
### 2.3 Implement use case
## 3. Code structure
### 3.1 Classes
- AI
- Board
- Database
- Game
- Match
- Piece: Not implement as class
- Player
- String
### 3.2 Actual code
- Chess
- Helper
## 4. Demonstration
### 4.1 Player-player
### 4.1 Player-AI
## 5. QnA
