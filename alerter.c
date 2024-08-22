#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

// Simulate network alert function that can be controlled for testing
int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    // To simulate a failure, always return 500 for testing purposes
    return 500; // Change this to 200 for success
}

void alertInCelcius(float farenheit) {
    // Convert Fahrenheit to Celsius
    float celcius = (farenheit - 32) * 5 / 9;
    
    // Get the response code from the network alert function
    int returnCode = networkAlertStub(celcius);
    
    // Increment failure count if return code is not 200
    if (returnCode != 200) {
        alertFailureCount++;
    }
}

int main() {
    // Call alertInCelcius with sample temperatures
    alertInCelcius(400.5);  // This should fail if networkAlertStub returns 500
    alertInCelcius(303.6);  // This should also fail if networkAlertStub returns 500
    
    // Check the number of failed alerts
    printf("%d alerts failed.\n", alertFailureCount);
    
    // Validation message
    if (alertFailureCount == 2) {
        printf("All is well (expected failures accounted for!)\n");
    } else {
        printf("FALSE POSITIVE! Expected failure but succeeded\n");
    }
    
    return 0;
}
