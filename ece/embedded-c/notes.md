### Setting a bit
Use the bitwise OR operator (|) to set a bit
`REGA |= 1 << x`

### Clearing a bit
Use the bitwise AND operator (&) to clear a bit
`REGA &= ~(1 << x)`

### Toggling a bit
Use the bitwise XOR operator (^) to toggle a bit
`REGA ^= 1 << x`

### Read a bit
```c
if(REGA & (1 << x)) {
    // DO SOMETHING
} else {
    // DO SOMETHING ELSE
}

// Alternative

boolean bit = (REGA >> x) & 1;
```

### DDRX, PORTX, PINX
```
Port B
_ _ _ _ _ _ _ _ 
7 6 5 4 3 2 1 0
```

#### DDRX (Data Direction Register)
This is used to store the type of each pin in the port,
0 -> Input  
1 -> Output
```c
DDRB = 0b00000001; //0th pin is output, 7th-1st bit is input  
```

#### PORTX (Set values and states)

PORTX register stores the state value (HIGH/LOW) for 
each *output pin* and whether pull-up resistors are
(activated/decativated) for each *input pin*  

So continuing previous code,
```c
PORTB |= 1 << 0; // Set PB0 (output) to hold value 1
PORTB &= ~(1 << 4) // Deactivate PB4 (input) pull-up resistor (tristate)
PORTB |= 1 << 3; // Activate PB3 (input) pull-up resistor
```

### PINX (Read current state)

PINX register reads and stores the status of all pins in the port.

For an *input pin* it stores the logic-level given to that pin,
for an *output pin* it stores the bit that was previously output from
that pin

```c
boolean bit3, bit0;
bit3 = (PINB >> 3) && 1; // Stores the value given to PB3 (input)
bit0 = (PINB >> 0) && 1; // Stores the output of PB0
```

