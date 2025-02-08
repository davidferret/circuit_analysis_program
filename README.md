# Circuit Analysis Project

This C project helps you analyze electrical circuits by calculating voltage, power, and total power for a given set of resistances and currents. It works with both series and parallel circuits and even provides a simple visualization of the circuit.

You start by selecting whether you're analyzing a series or parallel circuit. The project then takes in resistor values and current levels, calculates voltage and power for each resistor, and sums up the total power for the circuit. If needed, you can export the results to a text file for documentation.

I built this project because I’ve always been interested in how circuits work and wanted a way to quickly run calculations without doing them manually. It was a fun way to apply electrical theory to something practical, and I hope it makes circuit analysis easier for you too!

## Example Output
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

