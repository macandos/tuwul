# tuwul
A small, esoteric programming language thats designed to be as UwU as possible

## TODO
- [x] Lexer
- [x] Parser
- [x] Interpreter
- [ ] CLI
- [ ] Makefile

## Features
Tuwul has 7 commands, `uwu`, `owo`, `ywy`, `twt`, `ewe`, `awa`, and `iwi`. <br>
Like other esoteric languages, Tuwul has an int array, which is your program.<br> <br>

- `uwu` and `owo` increment and decrement the integer in that position of the array.
- `twt` and `ywy` move the posiiton of the array you're editing.
- `ewe` and `awa` are syntax for a loop. A loop would keep going until the current value of the position is 0.
- `iwi` gets the value of the position - 1, and copies it to the current position's value.

These values will then be interpreted through ASCII. <br>
So far, Tuwul allows you to do 2 things:
- Print
- Concat

You can print stuff using `pp <text>`,
and you can concat strings using `cc <arg1> <arg2>`
