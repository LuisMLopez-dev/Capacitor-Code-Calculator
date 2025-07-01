//Header Files
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function Prototypes
void capacitorCodeConverter(int capacitorCode);

int main(void){
    int userCapacitorCode = 0;
    
    do{
        printf("Enter the numerical code on your capacitor: (Range: 1 to 999) ");
        scanf("%d", &userCapacitorCode);
    }while(userCapacitorCode < 1 || userCapacitorCode > 999); //Checks to see if the user's input is in the valid range of 1 to 999

    if(userCapacitorCode == 101){ //Checks if the user's capacitor code is specifically 101
        printf("The value of you capacitor is 100 pF\n");  //If so, print 100 because a capacitor code of 101 is equivalent to 100 pF
    }
    else if(userCapacitorCode < 101){ //Else, then check if the user's capacitor code is in the range of 1 to 100
        printf("The value of your capacitor is %d pF\n", userCapacitorCode); //If so, then the capacitance is equal to the code in pF. For example, code 50 is 50 pF
    }
    else{
        capacitorCodeConverter(userCapacitorCode); //Otherwise, then the code is in the range of 102 to 999
    }
    return 0; //End of program
}

void capacitorCodeConverter(int capacitorCode){ //Takes the capacitor code of the user and converts it to it's equivalent capacitance

    printf("Function Called\n");
}
