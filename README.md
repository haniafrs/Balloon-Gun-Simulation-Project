# Balloon-Gun-Simulation-Project
This C++ project models a game using Discrete Mathematics. It represents objects as a Finite Set within a 2D Cartesian Product grid. Movement follows an Arithmetic Sequence ($y_n = y_{n-1} - 1$), while hit detection uses Propositional Logic ($P \land Q$). The game loop tracks Set Cardinality, ending when the active set is empty ($|B|=0$).

---

## 1. Introduction
The **Balloon-Gun Simulator** is a 2-player, turn-based console application. It bridges the gap between **Discrete Mathematics** and **Computer Science** by showing how math logic runs a game engine without complex physics libraries.

---

## 2. Project Overview
* **Gameplay:** A strategic battle where 2 players pop rising balloons.
* **Interaction:** Input an **X-coordinate** (Column) to fire.
* **Scoring:** +10 Points for every successful hit.
* **End State:** Game stops when the balloon set is empty.

---

## 3. Background
Unlike modern games that use smooth, continuous movement, this project is built on **Discrete Logic**:
* **Grid-Based:** Every position is a fixed integer.
* **Step-Movement:** Balloons move in jumps, not slides.
* **Logic-Driven:** Hits are calculated using mathematical truth values.

---

## 4. Methodology
The game follows a strict cyclic loop:
1.  **Fly Phase:** Balloons move up ($y = y - 1$).
2.  **Game Area:** The grid is drawn using ASCII characters.
3.  **Input:** Player enter a number in between the prompted range.
4.  **Check:** Math logic validates the hit.



---

## 5. Discrete Concepts Used
* **Cartesian Product:** The grid is defined as $X \times Y$ coordinates.
* **Arithmetic Sequence:** Constant movement with common difference $d = -1$.

* **Propositional Logic:** Hit detection using the formula: $p \land \neg q \land r$.

* **Set Cardinality:** Game loop runs until the set of active balloons is $\emptyset$ (Zero).

---

## 6. Future Enhancements
* **Obstacle Subsets:** Adding shields that block shots using set-intersection.
* **GUI:** Moving from ASCII to a Graphical User Interface.

---

## 7. Setup & Run
1. Open DEV C++ or any suitable compiler VSCode etc.
2. Compile the code and make the file.
3. Run: your file.
