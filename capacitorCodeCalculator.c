#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Function Prototypes
void capacitorCodeConverter(int capacitorCode);

int main(void){
    int userCapacitorCode = 0;
    
    do{
        printf("Enter the code on your capacitor: (Range: 1 to 999) ");
        scanf("%d", &userCapacitorCode);
    }while(userCapacitorCode < 1 || userCapacitorCode > 999);

    if(userCapacitorCode < 102){
        printf("The value of you capacitor is %d \n", userCapacitorCode);
    }
    else{
        capacitorCodeConverter(userCapacitorCode);
    }

    printf("\nHello, world!\n");
    return 0;
}

void capacitorCodeConverter(int capacitorCode){

    printf("Function Called\n");
}
