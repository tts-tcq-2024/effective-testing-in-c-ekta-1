#include <stdio.h>
#include <assert.h>

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    printf("ALERT: Temperature is %.1f celcius.\n", celcius);
    return (celcius > 250) ? 500 : 200;
}

void alertInCelcius(float farenheit) {
    float celcius = (farenheit - 32) * 5 / 9;
    if (networkAlertStub(celcius) != 200) {
        alertFailureCount++;
    }
}

void testAlertFailureCount() {
    alertFailureCount = 0;  // Reset before testing

    // Test cases
    alertInCelcius(200); // Expected: No failure
    assert(alertFailureCount == 0);

    alertInCelcius(300); // Expected: 1 failure
    assert(alertFailureCount == 1);

    alertInCelcius(150); // Expected: No additional failures
    assert(alertFailureCount == 1);

    printf("All tests passed successfully!\n");
}

int main() {
    testAlertFailureCount();
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
