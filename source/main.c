#include <wiiuse/wpad.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <gccore.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

int main(int argc, char **argv) {
    // Initialize video and input
    VIDEO_Init();
    WPAD_Init();
    rmode = VIDEO_GetPreferredMode(NULL);
    xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
    console_init(xfb, 20, 20, rmode->fbWidth, rmode->xfbHeight, rmode->fbWidth * VI_DISPLAY_PIX_SZ);
    VIDEO_Configure(rmode);
    VIDEO_SetNextFramebuffer(xfb);
    VIDEO_SetBlack(false);
    VIDEO_Flush();
    VIDEO_WaitVSync();
    if (rmode->viTVMode & VI_NON_INTERLACE) VIDEO_WaitVSync();
    printf("\x1b[2;0H");
    
    
    // Variables for inputs
    char num1[10] = "";
    char num2[10] = "";
    char operator = 0;
    
    // Input first number
    printf("Welcome to wcalc!\n");
    printf("The controls are:\n");
	printf("HOME = 0\n");
	printf("1 = 1\n");
	printf("2 = 2\n");
	printf("A = 3\n");
	printf("up = 4\n");
	printf("down = 5\n");
	printf("left = 6\n");
	printf("right = 7\n");
	printf("+ = 8\n");
	printf("- = 9\n");
	printf("B = next step\n");
	printf("please enter the first number:\n");
    
    while (1) {
        VIDEO_WaitVSync();
        WPAD_ScanPads();
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) { 
            strcat(num1, "0");
            printf("\rnumber 1: %s\n", num1);
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_1) { 
            strcat(num1, "1"); 
            printf("\rnumber 1: %s\n", num1); 
       }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_2) { 
            strcat(num1, "2"); 
            printf("\rnumber 1: %s\n", num1); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_A) { 
            strcat(num1, "3"); 
            printf("\rnumber 1: %s\n", num1); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_UP) { 
            strcat(num1, "4"); 
            printf("\rnumber 1: %s\n", num1); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_DOWN) { 
            strcat(num1, "5"); 
            printf("\rnumber 1: %s\n", num1); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_LEFT) { 
            strcat(num1, "6"); 
            printf("\rnumber 1: %s\n", num1); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_RIGHT) { 
            strcat(num1, "7"); 
            printf("\rnumber 1: %s\n", num1); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_PLUS) {
            strcat(num1, "8"); 
            printf("\rnumber 1: %s\n", num1); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_MINUS) { 
            strcat(num1, "9"); 
            printf("\rnumber 1: %s\n", num1);  
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_B) { 
            break; 
        }
    }
    
    printf("\033[2J"); // clear the screen
	printf("\x1b[2;0H"); // send cursor to row 2, column 1
    printf("Welcome to wcalc!\n");
	printf("The controls are:\n");
	printf("HOME = 0\n");
	printf("1 = 1\n");
	printf("2 = 2\n");
	printf("A = 3\n");
	printf("up = 4\n");
	printf("down = 5\n");
	printf("left = 6\n");
	printf("right = 7\n");
	printf("+ = 8\n");
	printf("- = 9\n");
	printf("B = next step\n");
	printf("please enter the second number:\n");
    
    while (1) {
        VIDEO_WaitVSync();
        WPAD_ScanPads();
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME) { 
            strcat(num2, "0");
            printf("\rnumber 2: %s\n", num2);
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_1) { 
            strcat(num2, "1"); 
            printf("\rnumber 2: %s\n", num2); 
       }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_2) { 
            strcat(num2, "2"); 
            printf("\rnumber 2: %s\n", num2); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_A) { 
            strcat(num2, "3"); 
            printf("\rnumber 2: %s\n", num2); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_UP) { 
            strcat(num2, "4"); 
            printf("\rnumber 2: %s\n", num2); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_DOWN) { 
            strcat(num2, "5"); 
            printf("\rnumber 2: %s\n", num2); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_LEFT) { 
            strcat(num2, "6"); 
            printf("\rnumber 2: %s\n", num2); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_RIGHT) { 
            strcat(num2, "7"); 
            printf("\rnumber 2: %s\n", num2); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_PLUS) {
            strcat(num2, "8"); 
            printf("\rnumber 2: %s\n", num2); 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_MINUS) { 
            strcat(num2, "9"); 
            printf("\rnumber 2: %s\n", num2);  
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_B) { 
            break; 
        }
    }
    
    printf("\033[2J"); // clear the screen
	printf("\x1b[2;0H"); // send cursor to row 2, column 1
	printf("Welcome to wcalc!\n");
	printf("The controls are:\n");
	printf("up = Addition\n");
	printf("down = Subtraction\n");
	printf("left = Multiplication\n");
	printf("right = Division\n");
	printf("please enter the operator:\n");
    
    while (1) {
        VIDEO_WaitVSync();
        WPAD_ScanPads();
        if (WPAD_ButtonsDown(0) & WPAD_BUTTON_UP) { 
            operator = '+'; break;
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_DOWN) { 
            operator = '-'; break; 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_LEFT) { 
            operator = '*'; break; 
        }
        else if (WPAD_ButtonsDown(0) & WPAD_BUTTON_RIGHT) { 
            operator = '/'; break; 
        }
    }
    
    // Convert strings to integers
    int num1Int = atoi(num1);
    int num2Int = atoi(num2);
    int result = 0;
    
    switch (operator) {
        case '+': result = num1Int + num2Int; break;
        case '-': result = num1Int - num2Int; break;
        case '*': result = num1Int * num2Int; break;
        case '/': 
            if (num2Int != 0) {
                result = num1Int / num2Int; 
            } else {
                printf("error: you cannot divide by zero. you should have known this!\n");
                exit(1);
            }
            break;
    }
    
    printf("%d %c %d = %d!\n", num1Int, operator, num2Int, result);
    printf("press any key to exit...\n");
    
    while (1) {
        WPAD_ScanPads();
        if (WPAD_ButtonsDown(0)) {
            printf("exiting...\n");
            exit(0);
        }
    }
    
    VIDEO_WaitVSync();
    
    return 0;
}