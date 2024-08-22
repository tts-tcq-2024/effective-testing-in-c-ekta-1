#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    if (celcius > 250) {
        return 500; // Simulate failure
    }
    return 200; // Simulate success
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlertStub(celcius);
    if (returnCode != 200) {
        // Increment failure count if return code is not 200
        alertFailureCount += 1;
    }
}

void testAlertFailureCount() {
    // Reset alertFailureCount to 0 before running tests
    alertFailureCount = 0;
    
    // Test cases
    alertInCelcius(200); // Should not fail (celcius = 93.3, less than 250)
    printf("AlertFailureCount = %d\n", alertFailureCount);
    assert(alertFailureCount == 0);
    
    alertInCelcius(300); // Should fail (celcius = 148.9, more than 250)
    printf("AlertFailureCount = %d\n", alertFailureCount);
    assert(alertFailureCount == 1);
    
    alertInCelcius(150); // Should not fail (celcius = 65.6, less than 250)
    printf("AlertFailureCount = %d\n", alertFailureCount);
    assert(alertFailureCount == 1);
    
    printf("All tests are passed successfully!\n");
}

int main() {    
    testAlertFailureCount();
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
