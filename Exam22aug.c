
#include <stdio.h>

// int checkSeat(char seatNo[]){
//     int wrongEntry=0;
//     for(int n=1; n<=5; n++){
//         if(seatNo[0] != "A"+n || seatNo[0] != "B%d",&n || seatNo[0] != "C%d",&n){
//             printf("A%d\n", &n);
//             wrongEntry=1;
//         }
//         else wrongEntry=0;
//     }
//     if(wrongEntry > 0) showSeat(seatNo);
//     return wrongEntry;
// }

int getLength(char message[]){
        int c=0; 
        while (message[c] != '\0') c++;
        return c;
};

void showSeat(char seatNo[]) {
    printf("Choose your seat: eg.A1 or B2 etc. \n");
    int i=0;
    do{
        if(i==0) printf("A ");
        else if(i==1) printf("B ");
        else printf("C ");
        printf("-");
        for(int j= 0; j<5; j++){
            printf(" "); 
            printf("%d",j+1);
        }
        printf("\n"); 
        i++;
     }while(i<3);

    scanf("%s", seatNo);
    printf("You have chosen seat number: %s\n", seatNo);
    printf("It costs $20 \n");
};

void isConfirmed(char confirmed[], char seatNo[]){
    printf("Are you confirmed? Y : N \n");
    scanf("%s", confirmed);
    printf("You said %s \n", confirmed);
}

void checkConfirm(char confirmed[], char seatNo[]) {
    if(confirmed[0]=='N') {
            printf("Choose your seat again \n");
            showSeat(seatNo);
            isConfirmed(confirmed, seatNo);
        }
    else if(confirmed[0]=='Y') printf("Thanks. Please proceed to payment. \n");
    else {
            printf("!! You entered invalid seat number !! \n");
            showSeat(seatNo);
            isConfirmed(confirmed, seatNo);
        }
}

void getPayment(int creditCardNo) {
    printf("Enter your last 4 digits credit card number. \n");
    scanf("%d", &creditCardNo);

    if(creditCardNo >= 1000 && creditCardNo < 10000 ) printf("*** Thank you. You have booked your seat.***\n");
    else {
        printf("You entered invalid numbers!! \n");
        getPayment(creditCardNo);
    }
}

int main() {
    char gender;
    char name[50];
    char message[]= " Start your Movie ticket booking here ";
    char seatNo[10];
    char confirmed[10];
    int creditCardNo;
    int wrongEntry=0;


    int count = getLength(message);
    printf("\n");

    for(int i=0; i<3; i++){
        printf("*");
            if(i==0 || i==2) {
                printf("**");
                for(int j= 0; j<count-4; j++){
                    printf("-"); 
                }
            printf("***");
            }
            else if(i==1) {
                printf("%s",message);
                printf("*");
            }
        printf("\n");
    }

    printf("\n");

    printf("Enter your gender M for Male / F for Female / other: ");
    scanf("%c", &gender);
    printf("Enter your first name:");
    scanf("%s",name);
        switch(gender){
            case 'M':
                printf("--------- ");
                printf("Welcome Mr.%s!!", name);
                printf(" ---------\n");
                break;
            case 'F':
                printf("--------- ");
                printf("Welcome Ms.%s!!", name);
                printf(" ---------\n");
                break;
            default:
                printf("--------- ");
                printf("Welcome %s!!", name);
                printf(" ---------\n");
                break;
        };
   
    
    showSeat(seatNo);
    
    printf("Are you confirmed? Y : N \n");
    scanf("%s", confirmed);
    printf("You said %s \n", confirmed);

    while(confirmed[0]=='N' || confirmed[0]!='Y'){
        if(confirmed[0]!='N' || confirmed[0]!='Y') printf("You entered invalid answer!! \n");
        printf("Choose your seat again \n");
        showSeat(seatNo);
        isConfirmed(confirmed, seatNo);
    }
    
    printf("Thanks. Please proceed to payment. \n");

    getPayment(creditCardNo);
    
        
    return 0;
};
