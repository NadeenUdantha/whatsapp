

#include <iostream>
#include <stdlib.h>
#include <windows.h>

using namespace std;

void adbShell(string cmd)
{
    // your adb path
    string cmd2 = "\"N:/Program Files/Droid4X/adb.exe\" -d shell "+cmd;
    system(cmd2.c_str());
    cmd2.clear();
}
void SendMsg()
{
    // whatsapp send button x y coordinations
    adbShell("input tap 450 800");
}
void InputMsg(string text)
{
    string txt = "";
    for(unsigned int x = 0;x < text.length();x++)
    {
        // space to %s
        if(text[x] == ' ')
        {
            txt += "%s";
        }
        else
            txt += text[x];
    }
    adbShell("input text "+txt);
}
int main()
{
    adbShell("ls");
    system("cls");
    while(true)
    {
        string msg = "";
        getline(cin,msg);
        if(msg == "" || msg.empty())continue;
        if(msg == "cls")
        {
            system("cls");
            continue;
        }
        InputMsg(msg);
        Sleep(100);
        SendMsg();
    }
    return 0;
}

