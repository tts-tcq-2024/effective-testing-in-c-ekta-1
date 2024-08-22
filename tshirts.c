#include <stdio.h>
#include <assert.h>

char size(int cms) {
    // Handle cases where cms is below 38
    if (cms < 38) {
        return '\0'; // Return null character for out-of-range values
    } 
    // Handle cases from 38 to 42 inclusive
    else if (cms >= 38 && cms <= 42) {
        return 'M';
    } 
    // Handle cases where cms is greater than 42
    else if (cms > 42) {
        return 'L';
    }
    // Handle cases where cms is zero or negative
    return '\0'; // Default return value
}

int main() {
    // Test boundary values and beyond
    assert(size(37) == '\0'); // Below lower boundary
    assert(size(38) == 'M');  // Lower boundary
    assert(size(39) == 'M');  // Inside range
    assert(size(40) == 'M');  // Inside range
    assert(size(42) == 'M');  // Upper boundary
    assert(size(43) == 'L');  // Above upper boundary

    // Test values that should not fit any category
    assert(size(-1) == '\0'); // Negative value
    assert(size(0) == '\0');  // Zero value

    printf("All is well (maybe!)\n");
    return 0;
}
