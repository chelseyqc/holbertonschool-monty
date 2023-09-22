### Script descriptions
[push.c](https://github.com/chelseyqc/holbertonschool-monty/blob/master/push.c) - The opcode that pushes an element to a stack. If `<int>` is not an integer or if there's no argument given, it prints an error message and exits with the status `EXIT_FAILURE`
- Usage: `push <int>`

[pall.c](https://github.com/chelseyqc/holbertonschool-monty/blob/master/pall.c) - The opcode that prints all the values on the stack, starting from the top of the stack. If the stack is empty, don't print anything.
- Usage: `pall`

[pint.c](https://github.com/chelseyqc/holbertonschool-monty/blob/master/pint.c) - The opcode that prints the value at the top of the stack, followed by a new line. If the stack is empty, it prints an error message followed by a new line, and exits with the status `EXIT_FAILURE`
- Usage: `pint`

[pop.c](https://github.com/chelseyqc/holbertonschool-monty/blob/master/pop.c) - The opcode that removes the top element of the stack. If the stack is empty, it prints an error message followed by a new line and exits with the status `EXIT_FAILURE`
- Usage: `pop`

[swap.c](https://github.com/chelseyqc/holbertonschool-monty/blob/master/swap.c) - The opcode that swaps the top two elements of the stack. If the stack contains less than two elements, it prints an error message followed by a new line, and exits with the status `EXIT_FAILURE`
- Usage: `swap`

[add.c](https://github.com/chelseyqc/holbertonschool-monty/blob/master/add.c) - The opcode that adds the top two elements of the stack. The result is stored in the second top element of the stack, and the top element is removed. 
- Usage: `add`

[nop.c](https://github.com/chelseyqc/holbertonschool-monty/blob/master/nop.c) - The opcode that doesn't do anything.
- Usage: `nop`
