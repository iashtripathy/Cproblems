#include<stdio.h>
#define on 1
#define off 0
//off -> indicates off state
//1 -> indicated on state
int startLed=off,stopLed=off;
int startButton=off;
int buttonOne=off,buttonTwo=off;
int ledOne=off,ledTwo=off;
int power=off;

//case 1,case 2,case 3
void func1(int *power,int *startButton,int *startLed,int *stopLed,int *buttonOne,int *buttonTwo,int *ledOne,int *ledTwo){
    if(*power){
        *stopLed=on;
    }
    //case 2
    if(*startButton){
        if(*buttonOne && !*buttonTwo){
            *ledOne=on;
        }
        //printf("%d",ledOne);
        if(*buttonTwo && !*buttonOne){
            *ledTwo=on;
        }
        *startLed=on;
    }
    //case 3
    if(*startLed && !*stopLed){
        if(*buttonOne){
            *ledOne=on;
        }
        if(*buttonTwo){
            *ledTwo=on;
        }
    }
}

//case 4 and case 5
void func2(int *power,int *startButton,int *startLed,int *stopLed,int *buttonOne,int *buttonTwo,int *ledOne,int *ledTwo){
    //case 4
    if(*startButton){
        if(*startLed){
            *stopLed=off;
        }
    }
    //case 5
    if(!*power){
        *startLed=off;
        *stopLed=off;
        *ledOne=off;
        *ledTwo=off;
    }
}

int main(void){
    int choice;
    printf("power button for on off\n");
    printf("start button to start playing with led's\n");
    printf("buttonOne to power on off ledOne\n");
    printf("buttonTwo for powering on off ledTwo");
    printf("Do you wish to start the led show.1 for yes,,,0 for No\n");
    scanf("%d",&choice);
    while(choice){
        printf("Enter 1 to power on power button else 0 to power off\n");
        scanf("%d",&power);
        printf("Enter 1 to on the start button else 0 to off it\n");
        scanf("%d",&startButton);
        printf("Enter 1 to on buttonOne else 0 to off buttonOne\n");
        scanf("%d",&buttonOne);
        printf("Enter 1 to on buttonTwo else 0 to off buttonTwo\n");
        scanf("%d",&buttonTwo);
        func1(&power,&startButton,&startLed,&stopLed,&buttonOne,&buttonTwo,&ledOne,&ledTwo);
        func2(&power,&startButton,&startLed,&stopLed,&buttonOne,&buttonTwo,&ledOne,&ledTwo);
        printf("power:%d\n",power);
        printf("startButton:%d\n",startButton);
        printf("startLed:%d\n",startLed);
        printf("stopLed:%d\n",stopLed);
        printf("buttonOne:%d\n",buttonOne);
        printf("buttonTwo:%d\n",buttonTwo);
        printf("ledOne:%d\n",ledOne);
        printf("ledTwo:%d\n",ledTwo);
        printf("Do you want to continue led show:\n 1 for Yes 0 for No\n");
        scanf("%d",&choice);
    }
    return 0;
}
