#ifdef __WIN32
#define ISWINDOWS

#elif __WIN64
#define ISWINDOWS

#else
#define ISPOSIX
#endif

#ifdef ISWINDOWS

#ifndef CONSOLE_H
#define CONSOLE_H

#define SYSCLEANSCREEN "CLS"

// windows
#include <windows.h>
#include <conio.h>
#include <string>

void clearScreen() {
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

void gotoXY(int x, int y) {
    COORD pos = {x, y};
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut, pos);
}

void setTextAndBackgroundColor(int ForgC, int BackC) {
   WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

#endif

#endif

#ifdef ISPOSIX

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string>
#include <iostream>

/*
 * color of output
 */
#define CONSLOECLEANSCREEN   "clear"
#define NONE                 "\e[0m"
#define BLACK                "\e[0;30m"
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;31m"
#define L_RED                "\e[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"

/*
 * effects of output
 */
#define BOLD                 "\e[1m"
#define UNDERLINE            "\e[4m"
#define BLINK                "\e[5m"
#define REVERSE              "\e[7m"
#define HIDE                 "\e[8m"
#define CLEAR                "\e[2J"
//#define CLRLINE              "\r\e[K" //or "\e[1K\r"

/*
 * cursor control
 */
#define SETCURSORPOS        "\033[%d;%dH"
#define RESETCURSOR         "\033[H"
#define HIDECURSOR          "\033[?25l"
#define SHOWCURSOR          "\033[?25h"
#define HIGHT_LIGHT         "\033[7m"
#define UN_HIGHT_LIGHT      "\033[27m"
#define CLRLINE             "\033[K"

int getch(void)
{
     struct termios tm, tm_old;
     int fd = 0, ch;
     if (tcgetattr(fd, &tm) < 0) {
          return -1;
     }
     tm_old = tm;
     cfmakeraw(&tm);
     if (tcsetattr(fd, TCSANOW, &tm) < 0) {
          return -1;
     }
     ch = getchar();
     if (tcsetattr(fd, TCSANOW, &tm_old) < 0) {
          return -1;
     }
     return ch;
}

void clearScreen(){
     printf("\033[2J");
}

void cursorControl(int cursorpos_x, int cursorpos_y, std::string control_mode){
     if(control_mode == SETCURSORPOS){
          printf(SETCURSORPOS, cursorpos_x, cursorpos_y);
     }
     else{
          std::cout<<control_mode;
     }
}

void outputControl(std::string outputcolor = "", std::string effects = "", std::string str = ""){
     std::cout<<outputcolor;
     std::cout<<effects;
     std::cout<<str;
}

void outputControl(std::string outputColor = "", std::string effects = "", char str = ' ', bool isEndl = false){
     std::cout<<outputColor;
     std::cout<<effects;
     if(!isEndl) std::cout<<str;
     else std::cout<<str<<std::endl;
}

#endif

#define BLOCKCHAR "█"

const std::string APPSCREEN = "\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\n\
████████████████████████████████████\
";

class console {
     public:
     console(){};
     ~console(){};

     void cleanConsloe(){
          clearScreen();
          consloe_string = "";
     }

     std::string get_string(){
          return consloe_string;
     }
     
     void change_string(std::string str){
          consloe_string = str;
     }

     void displayPic(std::string wd_str, std::string cl_str[wd_str.length()]){
          if(wd_str.size() != cl_str->size()) throw "Not a match string combination.";
          for(int i = 1;i <= wd_str.length();++i){
               outputControl(cl_str[i], "", wd_str[i], false);
          }
     }
     
     friend std::istream &operator >> (std::istream &fin, console a){
          fin>>a.consloe_string;
          return fin;
     }

     friend std::ostream &operator << (std::ostream &fout, console a){
          fout<<a.consloe_string;
          return fout;
     }

     friend console operator << (console &a, std::string str){
          a.consloe_string = str;
          return a;
     }


     friend std::string operator >> (console a, std::string &str){
          str = a.consloe_string;
          return str;
     }

     private:
     std::string consloe_string;
};
