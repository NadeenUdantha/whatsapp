/*
WhatsApp Messenger
Send whatsapp messages using adb (CodeBlocks project)

Copyright © 2016 Nadeen Udantha
<udanthan@gmail.com>

This program is free software: you can redistribute it and/or modify 
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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

