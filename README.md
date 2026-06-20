# Ace Interpreter

Ace Interpreter is a lightweight, tree-walk interpreter built in C++ for performing basic arithmetic operations. It follows a classic compiler pipeline: Lexical Analysis, Parsing (AST construction), and Interpretation.

## Features

* **Full Arithmetic Support**: Handles addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`).
* **Operator Precedence**: Correctly evaluates expressions based on BODMAS/PEMDAS rules.
* **Parentheses Handling**: Supports nested groupings to override standard precedence.
* **Single-line Comments**: Use the `#` symbol to document your code.
* **AST Visualization**: Includes a built-in printer to visualize the Abstract Syntax Tree structure.
* **Error Handling**: Basic detection for invalid arguments and division by zero.

## Project Structure

```text
Ace-Compiler/
├── main.cpp                 # Entry point: handles file I/O and pipeline orchestration
├── runner.bat               # Automation script for compilation and execution
├── src/                     # Folder for source code files (e.g., test.a)
├── lexer/                   # Tokenizes raw text into lexical units
├── parser/                  # Performs recursive descent parsing to build the AST
├── interpreter/             # Evaluates the AST nodes
├── AST/                     # Defines Expr, Binary, and Literal node structures
└── printer/                 # Contains AST visualization functions

```

## Prerequisites

* **C++ Standard**: C++17 or higher is required (uses `std::unique_ptr` and `std::stod`).
* **Compiler**: GCC/MinGW (specifically `g++`) or any C++17 compliant compiler.

## Usage

### 1. Writing your code

Create a file with the `.a` extension inside the `src/` folder.

> **Note:** Only basic arithmetic is supported. Unary operators (like `-5`) are not supported.

**Example (`src/test.a`):**

```python
# This is a comment
1 - (2 + 3) * 3 / 9

```

### 2. Running the Compiler

The `runner.bat` script handles both the compilation pipeline and quick testing execution flags.

### Option A: Compile and Run (Recommended for changes)

To build the binary using your modern C++17 configuration and immediately execute a script, use the `-c` flag followed by the path to your source file:

```bash
# both of them are supported
./runner.bat -c test.a

./runner.bat -C test.a

```

### Option B: Direct Execution (Fast Run)

If you haven't changed any C++ core codebase files and want to run your script using the existing compiled executable inside your build directory:

```bash

./runner.bat test.a

```

---

## How it Works

1. **Lexer**: Scans the `.a` file and breaks the text into a stream of `Tokens`. It ignores whitespace and skips anything following a `#`.
2. **Parser**: Uses a **Recursive Descent** strategy to transform the Token stream into an **Abstract Syntax Tree (AST)**. It ensures that `*` and `/` are deeper in the tree than `+` and `-`.
3. **AST (Abstract Syntax Tree)**: The tree is built using `std::unique_ptr` to ensure automated and safe memory management.
4. **Interpreter**: Performs a post-order traversal of the AST to calculate the final numerical result.
5. **Printer**: Generates a visual "sideways" representation of the tree in the console for debugging.

## Limitations

* No support for Unary Operators (e.g., `-5 + 3` will fail).
* No support for variables or complex logic (if/loops).
