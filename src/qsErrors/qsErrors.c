#include "qsErrors.h"
#include <string.h>

int qsErrors(int error, char* line, int len) {
    // Format error message based on error number
    switch(error) {
        case ARGS:
            strncpy(line, "The qSolve program was provided too few arguments", len);
            break;
        case A_OUT:
            strncpy(line, "The value for coefficient (A) is out of the 32-bit float range", len);
            break;
        case B_OUT:
            strncpy(line, "The value for coefficient (B) is out of the 32-bit float range", len);
            break;
        case C_OUT:
            strncpy(line, "The value for coefficient (A) is out of the 32-bit float range", len);
            break;
        case FORMAT:
            strncpy(line, "One or more of the coefficients entered has a format violation", len);
            break;
        case NULL_POINT:
            strncpy(line, "The address of X1 or X2 point to a NULL address", len);
            break;
        case PRODUCT:
            strncpy(line, "The product of entered coefficients is out of bounds of a 64-bit double", len);
            break;
    }
    
    return error;
}
