#include <bits/stdc++.h>
#include <windows.h>

int Speed, start = 2, pause = 3, end = 6;
/*
1 : VK_SPACE
2 : VK_RETURN
3 : VK_MENU
4 : VK_ESCAPE
5 : VK_TAB
6 : VK_CONTROL
*/

bool GetKeyboardEvent(int a){
    switch (a) {
        case 1:
            return  GetAsyncKeyState(VK_SPACE);
            break;
        case 2:
            return  GetAsyncKeyState(VK_RETURN);
            break;
        case 3:
            return  GetAsyncKeyState(VK_MENU);
            break;
        case 4:
            return  GetAsyncKeyState(VK_ESCAPE);
            break;
        case 5:
            return  GetAsyncKeyState(VK_TAB);
            break;
        case 6:
            return  GetAsyncKeyState(VK_CONTROL);
            break;
        default:
            break;
    }
}

void input(){
    puts("* Welcome to Qrebla's (Albert's) Clicker!");
    Sleep(100);
    puts("* Please input the expected CPS :");
    scanf("%d", &Speed);
    Speed = 1000 / Speed;
    puts("* Now choose keyboard controls...");
    printf("\t1 : spacebar\n\t2 : enter\n\t3 : alt\n\t4 : esc\n\t5 : tab\n\t6 : control\n");
    printf("to start:" );
    scanf("%d", &start);
    printf("\nto pause:" );
    scanf("%d", &pause);
    printf("\nto end:" );
    scanf("%d", &end);
    Sleep(100);
    puts("* Settings are ready, you can start whenever you want :)");
}

void LD7(){
	qrebla: {
        while(1)
             if(GetKeyboardEvent(start))//press space to start
                while(1) {
                    mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);//Mouse click st current spot
                    Sleep(Speed);//Click speed control
                    if(GetKeyboardEvent(pause)) goto qrebla; //Pause 
                    if(GetKeyboardEvent(end)) { //Stop  
                    	return;
                    }
                }
    }
}

int main() {
	input();
    LD7();
	puts("Thx 4 using!");
	Sleep(1000); 
	printf("\t\t Copyright 2020 - 2023 LQ_Studios");
	return 0;
}
