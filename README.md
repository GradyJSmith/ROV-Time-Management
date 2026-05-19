# MATE ROV Pilot Dashboard & Mission Timer

A custom desktop application built using **C++** and **Qt Widgets** to assist the ROV pilot and crew during the high-stakes 15-minute MATE ROV competition match. This dashboard provides a centralized, high-visibility countdown clock and an interactive product task list to optimize underwater mission strategy and time management.

---

## Features

* **Pausable Master Clock:** A prominent `QLCDNumber` digital display counting down from 15:00 minutes. 
* **Mission Control Buttons:** "Start Mission" and "Stop" buttons allow the crew to freeze the timer during unexpected technical pauses or pre-dive judge inspections.
* **Interactive Task Tracker:** A live label tracking current mission objectives (e.g., Structural Inspection, Lift Bag Deployment) so the entire team stays aligned on the active product.
* **Task Navigation:** Features dedicated buttons to cycle through steps dynamically:
    * `Previous`: Backtrack if a task needs to be re-attempted.
    * `Skip`: Advance past a task if strategy dictates shifting focus.
    * `Task Finished`: Log a completion and automatically advance to the next objective.

---

## Architecture & How It Works

The application leverages the **Qt Framework**'s core principles to deliver real-time accuracy:

* **Object Trees & Memory Management:** The core `QTimer` is instantiated using dynamic heap allocation (`new QTimer(this)`). By passing the `MainWindow` pointer (`this`) as the parent, Qt automatically manages the lifecycle and deletes the timer when the window closes, completely preventing memory leaks.
* **Signals & Slots:** The ticking mechanic relies on asynchronous event handling. The `QTimer::timeout` signal is connected directly to a custom C++ slot (`MainWindow::updateTimer()`). Every 1000ms, the operating system triggers this function to decrement the countdown pool.
* **Data Structures:** Mission steps are managed via a `QVector<QString>` dynamic array. Safe index bounds checking (`currentTaskIndex`) prevents standard memory segmentation faults or out-of-range crashes during intense piloting sequences.

---

## Prerequisites

To build and run this application, you will need:

* **Qt Creator** (IDE)
* **Qt 6.x** (or Qt 5.15+) with **Qt Widgets** modules installed
* A C++ compiler supporting **C++17** or higher (GCC, Clang, or MSVC)
* **CMake** (Build System)

---

## Installation & Setup

1.  **Clone the Repository:**
    ```bash
    git clone [https://github.com/your-team-username/ROV_Mission_Timer.git](https://github.com/your-team-username/ROV_Mission_Timer.git)
    cd ROV_Mission_Timer
    ```

2.  **Open in Qt Creator:**
    * Launch **Qt Creator**.
    * Select **Open Project** and open the `CMakeLists.txt` file in the root directory.
    * Select your desktop kit (e.g., Desktop Qt 6.x MinGW/GCC).

3.  **Build and Run:**
    * Click the **Build** button (Hammer icon) or press `Ctrl + B` (`Cmd + B` on macOS).
    * Click the **Run** button (Green play arrow) or press `Ctrl + R` (`Cmd + R` on macOS).

---

## Customizing Tasks for Your Competition

To update the dashboard with your team's specific props and mission workflow for the current season, open `mainwindow.cpp` and modify the task list initialization inside the constructor:

```cpp
// Modify these strings to match your specific product steps:
taskList.append("Setup & Calibration");
taskList.append("Product 1: Your Mission Task Here");
taskList.append("Product 2: Your Next Task Here");
```
