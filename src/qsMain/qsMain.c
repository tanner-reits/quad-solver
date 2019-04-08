#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../qsValidate/qsValidate.h"
#include "../qsSolve/qsSolve.h"
#include "../qsErrors/qsErrors.h"
#include "../qsGetLine/qsGetLine.h"
#include "../qsPutLine/qsPutLine.h"
#include "../qsResults/qsResults.h"
#include "../qsHelp/qsHelp.h"
//#include "../qsLogEnable/qsLogEnable.h"
#include "../qsLog/qsLog.h"

int main(int argc, char** argv) {
    // Variables for functions
    int ret;
    char line[256];
    int log   = 0;
    int nline = 256;
    int exit  = 0;
    double a  = 0;
    double b  = 0;
    double c  = 0;
    double x1 = 0;
    double x2 = 0;

    // Check if logging enable parameter passed as command line argument
//    if((argc > 1) && (atoi(argv[1]) == 1)) {
//        log  = qsLogEnable();
//        qsLog("Logging has been enabled");
//    }

    // Print program information header
    printf("JKK Engineers Quadratic Solver:\n");
    printf("  Version: 0.1.1\n");
    printf("  For Help type \"help\"\n");
    printf("  To exit, type \"exit\"\n");
    printf("  To toggle logging, type \"log\"\n\n");

    do {
        // Get input line
        if((ret = qsGetline(line, nline)) != OK) {
            qsErrors(ret, line, nline);
            if(log) {
                qsLog(line);
            }
        }

        // Check if user prompted for help
        if(strncmp(line, "help", nline) == 0) {
            qsHelp();
        }
        else if(strncmp(line, "exit", nline) == 0) {
            exit = 1;
        }
        else if(strncmp(line, "log", nline) == 0) {
            log ^= 1;
            if(log) {
                printf("Logging has been enabled\n");
            }
            else {
                printf("Logging has been disabled\n");
            }
        }
        else {
            // Validate input
            if(ret == OK) {
                if((ret = qsValidate(line, nline, &a, &b, &c)) != OK) {
                    qsErrors(ret, line, nline);
                }
                if(log) {
                    qsLog(line);
                } 
            }
            
            // Apply quad solver
            if(ret == OK) {
                if((ret = qsSolve(a, b, c, &x1, &x2)) > ROOT_2) {
                    qsErrors(ret, line, nline);
                }
                if(log) {
                    qsLog(line);
                }
            }

            // Check results
            if(ret <= ROOT_2) {
                if((ret = qsResults(ret, x1, x2, line, nline)) != OK) {
                    qsErrors(ret, line, nline);
                }
                if(log) {
                    qsLog(line);
                }
            }

            // Output results
            qsPutline(line, strnlen(line, nline));
        }
    } while(!exit);
    
    return OK;
}
