# 📝 Todo App

## 🌟 Overview
This project consists of two implementations of a simple Todo application:
1. **🖥️ GUI Version (raylib-based)**: A graphical interface using the Raylib library.
2. **💻 CLI Version**: A command-line-based implementation that takes user input via the terminal.

## 🔥 Features
### 🎨 GUI Version
- ✅ Users can enter a key (identifier) before adding tasks.
- 📝 Supports task input with a maximum of 10 tasks.
- 📋 Displays the entered key and list of tasks when finished.
- 🎮 Utilizes Raylib for rendering text and handling user input.

### 🏗️ CLI Version
- 📌 Users specify the number of tasks they want to enter.
- 🖊️ Tasks are entered via standard input and stored.
- 📄 The tasks are displayed in the terminal window and the GUI window.

## 📌 Requirements
- **For GUI Version:**
  - 🎮 Raylib library installed.
  - 🛠️ C compiler (e.g., GCC or Clang).
- **For CLI Version:**
  - 🏗️ Standard C library support.

## 📥 Installation
1. 📂 Clone the repository:
   ```sh
   git clone <repository_url>
   cd todo-app
   ```
2. 🛠️ Install Raylib (for GUI version):
   ```sh
   sudo apt install libraylib-dev # For Linux (Debian-based)
   ```
   For other operating systems, refer to [Raylib's official installation guide](https://www.raylib.com/).

## ⚙️ Compilation
### 🖥️ Compile the GUI Version:
```sh
gcc -o todo_gui todo_gui.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
./todo_gui
```

### 💻 Compile the CLI Version:
```sh
gcc -o todo_cli todo_cli.c
./todo_cli
```

## 🚀 Usage
### 🖥️ Running the GUI Version:
1. 🏁 Start the program.
2. 🔑 Enter a key (identifier) and press `Enter`.
3. ✍️ Enter tasks one by one and press `Enter` after each.
4. ✅ Press `Enter` on an empty input field to finish.
5. 📋 The entered key and task list will be displayed.

### 💻 Running the CLI Version:
1. 🏁 Run the program.
2. 🔢 Enter the number of tasks you want to add.
3. ✏️ Provide task descriptions as prompted.
4. 📄 The tasks will be displayed in the console and in a Raylib GUI.

## 📜 License
This project is licensed under the MIT License.
