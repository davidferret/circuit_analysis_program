# Circuit Analysis Program

This program calculates voltage, power, and total power for a given circuit based on user-inputted resistances and currents. It supports both series and parallel circuits and provides visualization and data export functionality.

- **Circuit Type Selection**: Allows users to analyze series or parallel circuits.
- **Voltage and Power Calculation**: Computes values for each resistor based on circuit type.
- **Total Power Computation**: Aggregates power consumption for the entire circuit.
- **Data Export**: Saves results to a text file for documentation.
- **Circuit Visualization**: Provides a basic textual representation of the circuit structure.

## Example Usage
```
Enter the number of resistors (max 100): 3
Enter the circuit type (1 for Series, 2 for Parallel): 1
Enter the resistance (ohms) for resistor 1: 10
Enter the value of current (A) for resistor 1: 0.5
Enter the resistance (ohms) for resistor 2: 20
Enter the value of current (A) for resistor 2: 0.5
Enter the resistance (ohms) for resistor 3: 30
Enter the value of current (A) for resistor 3: 0.5

 Resistance  Current   Voltage   Power
       10      0.50      5.00     2.50
       20      0.50     10.00     5.00
       30      0.50     15.00     7.50
                              Total    15.00

Circuit Diagram:
[ 10Ω ] --- [ 20Ω ] --- [ 30Ω ]

Results saved to 'circuit_analysis.txt'.

```

