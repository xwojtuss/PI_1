# FINITE_AUTOMATON

finite_automaton is a C programming project that simulates, like the name suggests, a finite automaton 𝑀 = (𝑄,Σ,𝛿,𝑞0,𝐹), where 𝑄 = {𝑞0,𝑞1,𝑞2,𝑞3}, Σ = {0,1}, 𝐹 = {𝑞0}, and the δ is defined as follows:
|States|0|1|
|-|-|-|
|q0|q2|q1|
|q1|q3|q0|
|q2|q0|q3|
|q3|q1|q2|

The currect state is displayed using ASCII characters, the state is displayed after 1 second, you can change this in the Makefile by modifying the SLEEP_TIME variable.

## Getting Started

These instructions will help you get a copy of the project up and running.

### Dependencies

- clang
- make

### Installing

1. Clone the repository:
```
git clone https://github.com/xwojtuss/finite_automaton.git
```

2. Navigate to the project directory:
```
cd finite_automaton
```

3. Run the make command to build the project:
```
make
```

## Running the project

You can either run the program with a string as a parameter made up of symbols from alphabet Σ:
```
./automaton [string]
```
or without parameters, the program will then read the symbols one by one from stdin until EOF is encountered:
```
./automaton
```


## Authors

* **Wojtek Kornatowski** - [xwojtuss](https://github.com/xwojtuss)
