#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int balance;
int cpu_balance;
int final_balance;

void hit() {
    srand(time(NULL));
    int chose = rand() % 12 + 1;
    int card = 0;
    int player_score = 0;

    

    switch (chose) {
    case 1:
        card = 2;
        break;
    case 2:
        card = 3;
        break;
    case 3:
        card = 4;
        break;
    case 4:
        card = 5;
        break;
    case 5:
        card = 6;
        break;
    case 6:
        card = 7;
        break;
    case 7:
        card = 8;
        break;
    case 8:
        card = 9;
        break;
    case 9:
        card = 10;
        break;
    case 10:
        card = 10;
        break;
    case 11:
        card = 10;
        break;
    case 12:
        card = 10;
        break;
    case 13:
        card = 11;
        break;
    }
    balance += card;
    cpu_balance += card;

}

void cpu() {
    int choice;
    int x = 1;

    srand(time(NULL));
    cpu_balance = rand() % (21 - 3 + 1) + 2;

    do {
        if(cpu_balance < 12) {
            hit();
        } else if(cpu_balance >= 12 && cpu_balance < 18) {
            choice = rand() % 100;
            if(choice < 66) {
                hit();
                continue;
            } else {
                x = 5;
            }
        } else if(cpu_balance >= 18) {
            x = 5;
        }
    } while(x < 5);  
        winner();
}

main() {
    int choice;
    int x = 1;


    srand(time(NULL));
    balance = rand() % (21 - 3 + 1) + 2;
    printf("score: %d\n", balance);

    do {
    printf("hit or stand?\n 1. hit:\n 2. stand:\n");
    scanf("%d", &choice);
    switch(choice) {
        case 1:
        hit();
        printf("your score: %d\n", balance);
        break;
        case 2:
        x = 5;
        cpu_balance = 0;
        final_balance = balance;

        cpu();

        exit;
        break;

    }
    } while(x < 5);
    
}

int winner() {
    printf("cpu score: %d\n", cpu_balance);
    printf("your score: %d\n", final_balance);
    if(cpu_balance>21 && final_balance>21) {
        printf("both lost");
        return 0;
    }
    if(cpu_balance>21) {
        printf("congratulations! you won!");
        return 0;
    }
    if(final_balance>21) {
        printf("you lost!");
        return 0;
    }

    if(final_balance>cpu_balance) {
        printf("congratulations! you won!");
        return 0;
    }
    if(cpu_balance>final_balance) {
        printf("you lost!");
        return 0;
    }
    if(cpu_balance=final_balance) {
        printf("draw");
        return 0;
    }
}
