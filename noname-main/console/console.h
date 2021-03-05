#ifndef _CONSOLE_WINDOWS_H
#define _CONSOLE_WINDOWS_H

#include <windows.h>

void WINDOWS_clearScreen() {
   HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   COORD coord = {0, 0};
   DWORD count;
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
      SetConsoleCursorPosition(hStdOut, coord);
   }
}

void WINDOWS_gotoXY(int x, int y) {
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

void WINDOWS_setTextAndBackgroundColor(int ForgC, int BackC) {
   WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

#endif
