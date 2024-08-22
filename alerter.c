#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

// Simple stub always simulating failure for testing
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return 500; // Simulate a failure
}

void alertInCelcius(float farenheit) {
    // Calculate Celsius
    float celcius = (farenheit - 32) * 5 / 9;
    
    // Check if the alert failed
    int returnCode = networkAlertStub(celcius);
    
    // Increment failure count if necessary
    alertFailureCount += (returnCode != 200);
}

int main() {
    // Call with sample temperatures
    alertInCelcius(400.5);
    alertInCelcius(303.6);
    
    // Output the number of failed alerts
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    
    return 0;
}
