#define UNICODE
#include <cstdlib>
#include <string>
#include <iostream>
#include <fcntl.h>
#include <windows.h>
using namespace std;
bool CheckStart();
bool CheckEnd();
int main()
{
    _setmode(_fileno(stdout), _O_U16TEXT);
    system("mode con cols=20 lines=4");
    system("title MouseAutoClicker");
    wcout << L"左鍵連點" << endl;
    wcout << L"Ctrl + F2 開始" << endl;
    wcout << L"Ctrl + F3 暫停" << endl;
    while (1)
    {
        if (CheckStart())
            while (1)
            {
                mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
                if (CheckEnd())
                    break;
            }
    }
    return 0;
}
bool CheckStart()
{

    if ((GetKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(VK_F2) & 0x8000))
        return true;
    else
        return false;
}
bool CheckEnd()
{
    if ((GetKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(VK_F3) & 0x8000))
        return true;
    else
        return false;
}