#include <bits/stdc++.h>
#include <iostream>
#include <windows.h>
using namespace std;

int Speed, start = 2, pause = 3, stop = 6;
/*
1 : VK_SPACE
2 : VK_RETURN
3 : VK_MENU
4 : VK_ESCAPE
5 : VK_TAB
6 : VK_CONTROL
*/

int GetKeyboardEvent(int a){
	
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
            break;
    }
}

int GetLetter(int num) {
	if(num != 7 && num != 8)
		return num;
	printf("Character:");
	char alpha;
	cin >> alpha;
	alpha = toupper(alpha);
	return (int)alpha;
}

void input(){
    
    puts("* Please input the expected CPS :");
    scanf("%d", &Speed);
    Speed = 1000 / Speed;
    puts("* Now choose keyboard controls...");
    printf("\t1 : spacebar\n\t2 : enter\n\t3 : alt\n\t4 : esc\n\t5 : tab\n\t6 : control\n\t7 : A-Z\n\t8 : 0-9\n");
    printf("to start:" );
    scanf("%d", &start);
    start = GetLetter(start);
    printf("\nto pause:" );
    scanf("%d", &pause);
    pause = GetLetter(pause);
    printf("\nto end:" );
    scanf("%d", &stop);
    stop = GetLetter(stop);
    Sleep(100);
    puts("* Settings are ready, you can start whenever you want :)");
    Sleep(1000);
}

void main_in_main(){
	oto: {
        while(1){
        	//if(GetKeyboardEvent(stop))  //Stop  
            //    return;
            if(GetKeyboardEvent(start)){
				while(1) {
	                mouse_event(MOUSEEVENTF_LEFTDOWN|MOUSEEVENTF_LEFTUP,0,0,0,0);//Mouse click st current spot
	                Sleep(Speed);//Click speed control
	                if(GetKeyboardEvent(pause)) goto oto; //Pause 
	                if(GetKeyboardEvent(stop)) return;
	            }
			}//press space to start
                
        }
    }
}

int main() {
	input();
    main_in_main();
	puts("Thx 4 using!");
	puts("Made by Albert(Qrebla) and 11400F");
	Sleep(1000); 
	
	return 0;
}
