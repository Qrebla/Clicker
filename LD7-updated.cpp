#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>
using namespace std;

int Speed, start = 2, pause = 3, stop = 6;
char alpha;
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
            return  GetAsyncKeyState(a);
    }
}

void input(){
    
    puts("* Please input the expected CPS :");
    scanf("%d", &Speed);
    Speed = 1000 / Speed;
    puts("* Now choose keyboard controls...");
    printf("\t1 : spacebar\n\t2 : enter\n\t3 : alt\n\t4 : esc\n\t5 : tab\n\t6 : control\n\t7 : A-Z\n\t8 : 0-9\n");
    printf("to start:" );
    scanf("%d", &start);
    if(start==7||start==8){
    	printf("Character:");
    	cin>>alpha;
    	alpha = toupper(alpha);
    	start = alpha;
    }
    printf("\nto pause:" );
    scanf("%d", &pause);
    if(pause==7||pause==8){
    	printf("Character:");
    	cin>>alpha;
    	alpha = toupper(alpha);
    	pause = alpha;
    }
    printf("\nto end:" );
    scanf("%d", &stop);
    if(stop==7||stop==8){
    	printf("Character:");
    	cin>>alpha;
    	alpha = toupper(alpha);
    	stop = alpha;
    }
    Sleep(100);
    puts("* Settings are ready, you can start whenever you want :)");
    Sleep(1000);
}

void main_in_main(){
	oto: {
        while(1){
        	//if(GetKeyboardEvent(stop))  //Stop  
            //    return;
            if(GetKeyboardEvent(start))//press space to start
                while(1) {
                    mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);//Mouse click st current spot
                    Sleep(Speed);//Click speed control
                    if(GetKeyboardEvent(pause)) goto oto; //Pause 
                    if(GetKeyboardEvent(stop)) { //Stop  
                    	return;
                    }
                }
            }
    }
}

int main() {
	input();
    main_in_main();
	puts("Thx 4 using!");
	Sleep(1000); 
	
	return 0;
}
