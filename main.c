#include <stdio.h>

void getUserInput(int resistance[], double current[], int *size, int *circuitType);
void calculateValues(int resistance[], double current[], double voltage[], double power[], int size, double *total_power, int circuitType);
void displayResults(int resistance[], double current[], double voltage[], double power[], int size, double total_power);
void saveResultsToFile(int resistance[], double current[], double voltage[], double power[], int size, double total_power);
void visualizeCircuit(int resistance[], int size, int circuitType);

int main(void) {
    int resistance[100], size, circuitType;
    double current[100], voltage[100], power[100], total_power = 0;
    
    getUserInput(resistance, current, &size, &circuitType);
    calculateValues(resistance, current, voltage, power, size, &total_power, circuitType);
    displayResults(resistance, current, voltage, power, size, total_power);
    saveResultsToFile(resistance, current, voltage, power, size, total_power);
    visualizeCircuit(resistance, size, circuitType);
    
    printf("Results saved to 'circuit_analysis.txt'.\n");
    return 0;
}

void getUserInput(int resistance[], double current[], int *size, int *circuitType) {
    printf("Enter the number of resistors (max 100): ");
    scanf("%d", size);
    
    if (*size > 100) {
        printf("Exceeding max size, setting to 100\n");
        *size = 100;
    }
    
    printf("Enter the circuit type (1 for Series, 2 for Parallel): ");
    scanf("%d", circuitType);
    
    for (int i = 0; i < *size; i++) {
        printf("Enter the resistance (ohms) for resistor %d: ", i + 1);
        scanf("%d", &resistance[i]);
        printf("Enter the value of current (A) for resistor %d: ", i + 1);
        scanf("%lf", &current[i]);
    }
}

void calculateValues(int resistance[], double current[], double voltage[], double power[], int size, double *total_power, int circuitType) {
    *total_power = 0;
    if (circuitType == 1) { // Series Circuit
        double total_resistance = 0;
        for (int i = 0; i < size; i++) {
            total_resistance += resistance[i];
        }
        double total_current = current[0]; // Same current in series circuit
        for (int i = 0; i < size; i++) {
            voltage[i] = resistance[i] * total_current;
            power[i] = total_current * voltage[i];
            *total_power += power[i];
        }
    } else { // Parallel Circuit
        double total_current = 0;
        for (int i = 0; i < size; i++) {
            voltage[i] = resistance[i] * current[i];
            power[i] = current[i] * voltage[i];
            total_current += current[i];
            *total_power += power[i];
        }
    }
}

void displayResults(int resistance[], double current[], double voltage[], double power[], int size, double total_power) {
    printf("%10s%9s%9s%9s\n", "Resistance", "Current", "Voltage", "Power");
    for (int i = 0; i < size; i++) {
        printf("%10d%9.2f%9.2f%9.2f\n", resistance[i], current[i], voltage[i], power[i]);
    }
    printf("%10s%9s%9s%9.2f\n", "", "", "Total", total_power);
}

void saveResultsToFile(int resistance[], double current[], double voltage[], double power[], int size, double total_power) {
    FILE *file = fopen("circuit_analysis.txt", "w");
    if (!file) {
        printf("Error creating file!\n");
        return;
    }
    
    fprintf(file, "%10s%9s%9s%9s\n", "Resistance", "Current", "Voltage", "Power");
    for (int i = 0; i < size; i++) {
        fprintf(file, "%10d%9.2f%9.2f%9.2f\n", resistance[i], current[i], voltage[i], power[i]);
    }
    fprintf(file, "%10s%9s%9s%9.2f\n", "", "", "Total", total_power);
    fclose(file);
}

void visualizeCircuit(int resistance[], int size, int circuitType) {
    printf("\nCircuit Diagram:\n");
    if (circuitType == 1) { // Series Circuit Visualization
        for (int i = 0; i < size; i++) {
            printf("[ %dΩ ]", resistance[i]);
            if (i < size - 1) {
                printf(" --- ");
            }
        }
    } else { // Parallel Circuit Visualization
        for (int i = 0; i < size; i++) {
            printf("[ %dΩ ]\n", resistance[i]);
        }
    }
    printf("\n");
}
