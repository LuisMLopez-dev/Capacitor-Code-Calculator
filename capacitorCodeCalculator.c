//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//Function Prototype
void capacitorCodeConverter(int capacitorCode, int multiplier);

int main(void){
    int userCapacitorCode = 0, multiplier = 0, userContinueStatus = 0;
    bool exitProgram = false;
    
    while(!exitProgram){
        do{
            printf("Enter the capacitor code: (1 - 999). Codes ending in 6 or 7 are invalid: "); //Capacitor must be between 1 and 999, and the third digit must not be a 6 or a 7
            scanf("%d", &userCapacitorCode);

            if(userCapacitorCode > 99){
                multiplier = userCapacitorCode % 10; //Obtains the multiplier by taking the value of the last digit of the number once it is at least 3 digits long
            }

            if(userCapacitorCode < 1 || userCapacitorCode > 999 || multiplier == 6 || multiplier == 7){ //If the user's input is invalid
                printf("\nInvalid Input! The capacitor code must be between 1 and 999, and the code must not end in a 6 or a 7.\nTry again\n\n");
            }
        }while(userCapacitorCode < 1 || userCapacitorCode > 999 || multiplier == 6 || multiplier == 7); //Repeat the do until user enters a valid input

        if(userCapacitorCode < 101){ //Check if the user's capacitor code is in the range of 1 to 100
            printf("The value of your capacitor is %d pF\n\n", userCapacitorCode); //If so, then the capacitance is equal to the code in pF. For example, code 50 is 50 pF
        }
        else{
            capacitorCodeConverter(userCapacitorCode, multiplier); //Otherwise, then the code is in the range of 101 to 999
        }

        do{
            printf("Enter another capacitor code? (1 = Yes, 0 = No): ");
            scanf("%d", &userContinueStatus);
            puts(""); //This is for spacing purposes
        }while(userContinueStatus != 0 && userContinueStatus != 1); //Checks for a valid input

        if(userContinueStatus == 1){ //If user wants to continue
            exitProgram = false; //Repeat the while loop
        }
        else{
            exitProgram = true; //Exit the while loop
        }
    }
    printf("The program has ended\n");
    return 0; //End of program
}

void capacitorCodeConverter(int capacitorCode, int multiplier){ //Takes the capacitor code of the user and converts it to it's equivalent capacitance
    int base = capacitorCode / 10; //First two digits of the capacitor code
    int multiplierValue = 1; //Will hold the equivalent of 10 to the power of the multiplier
    float capacitance = 0.00; //Stores the capacitance of the capacitor

    if(multiplier == 8){
        capacitance = base * 0.01; //Equivalent to 10 to the power of -2
    }
    else if(multiplier == 9){
        capacitance = base * 0.1; //Equivalent to 10 to the power of -1
    }
    else{
        for(int i = 0; i < multiplier; ++i){ //This for loop is used over pow() because that returns a double, and it could truncate the value
            multiplierValue *= 10; //This sticks to using integers to obtain the equivalent exponet value
        }
        capacitance = base * multiplierValue; //Equation to obtain capacitance from a capacitor code
    }

    if(capacitance > 999999.00){ //If the capacitance is in the micro range (multiplier = 5)
        printf("The capacitance of your capacitor is %.2f uF\n", capacitance / 1000000.00);
    }
    else if(capacitance > 999.00){ //If the capacitance is in the nano range (multiplier = 2, 3, or 4)
        printf("The capacitance of your capacitor is %.2f nF\n", capacitance / 1000.00);
    }
    else if(capacitance < 1.00){ //If the capacitance is in the femto range (multiplier = 8)
        printf("The capacitance of your capacitor is %.2f fF\n", capacitance * 1000);
    }
    else{ //If the capacitance is in the pico range (multiplier = 1 or 9)
        printf("The capacitance of your capacitor is %.2f pF\n", capacitance);
    }
}
