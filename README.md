Compiler_construction_project
Creating a VizuAll compiler


WizuAll Compiler
A compiler toolchain for WizuAll, a language for data visualization based on the CalciList vector calculator.

Project Overview
WizuAll is a domain-specific language designed for data visualization that extends the CalciList vector calculator. This project implements a complete toolchain for processing WizuAll programs:
1. Preprocessor: Extracts numeric data from input files
2. WizuAll Compiler: Parses WizuAll code and generates target language code
3. Visualization Output: Produces visualizations using target language libraries

Getting Started

Prerequisites
- Flex and Bison (for lexer/parser generation)
- C compiler (GCC)
- Python with data visualization libraries (matplotlib, numpy, pandas)

Building the Project
```bash
make clean
make
```

Project Structure

```
.
├── src/
│   ├── calcilist.h       Core data structures and functions
│   ├── calcilist.l       Lexer definition
│   ├── calcilist.y       Parser definition
│   ├── preprocessor/     Data extraction components
│   └── code_gen/         Target code generation modules
├── examples/             Example WizuAll programs
├── docs/                 Documentation
└── tests/                Test cases
```

 Implementation Plan

1. Design Phase
- [ ] Define extended language grammar
- [ ] Design code generation templates
- [ ] Design preprocessor workflow
- [ ] Document language semantics

2. Parser Implementation
- [ ] Extend CalciList lexer (calcilist.l)
- [ ] Extend CalciList parser (calcilist.y)
- [ ] Implement symbol table management
- [ ] Add support for control structures (if/else, while)

3. Syntax-Directed Translation
- [ ] Implement expression evaluation
- [ ] Add semantic actions for statement processing
- [ ] Design and implement visualization primitives
- [ ] Create type checking system

4. Target Code Generation (Deadline: April 21)
- [ ] Implement template-based code generation for Python
- [ ] Create visualization function templates
- [ ] Add support for all required visualization types
- [ ] Implement data conversion utilities

5. Final Refinements (Deadline: April 28)
- [ ] Add error handling and reporting
- [ ] Optimize code generation
- [ ] Add documentation and examples
- [ ] Perform testing and debugging

Language Features

Core CalciList Functionality
- Vector arithmetic operations (addition, subtraction, multiplication, division)
- Nested vectors/matrices
- Assignment statements

Added WizuAll Features
- Control structures (if/else conditionals, while loops)
- External function calls
- Visualization primitives:
  - Line plots
  - Histograms
  - Heat maps
  - Scatter plots
  - Statistical summaries
  - Clustering

Auxiliary Code Support
WizuAll allows embedding target language code (Python) directly using `<%` and `%>` delimiters, which will be copied verbatim to the output.

 Example WizuAll Program

```
<% import numpy as np %>

data = [1, 2, 3, 4, 5];
squared = data * data;

if (data[0] > 0) {
    plot(squared, title="Squared Values", xlabel="Index", ylabel="Value");
}

avg = stats(data);
histogram(data - avg, bins=10);
```
