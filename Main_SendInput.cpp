#define UNICODE
#include <fcntl.h>
#include <windows.h>

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
bool CheckStart();
bool CheckEnd();
void Clicker();
int main() {
  _setmode(_fileno(stdout), _O_U16TEXT);
  system("mode con cols=20 lines=4");
  system("title MouseAutoClicker");
  wcout << L"左鍵連點" << endl;
  wcout << L"Ctrl + F2 開始" << endl;
  wcout << L"Ctrl + F3 暫停" << endl;
  while (1) {
    if (CheckStart())
      while (1) {
        Clicker();
        if (CheckEnd()) break;
      }
  }
  return 0;
}
bool CheckStart() {
  if ((GetKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(VK_F2) & 0x8000))
    return true;
  else
    return false;
}
bool CheckEnd() {
  if ((GetKeyState(VK_CONTROL) & 0x8000) && (GetAsyncKeyState(VK_F3) & 0x8000))
    return true;
  else
    return false;
}
void Clicker() {
  enum sendInputs { MOUSE_DOWN, MOUSE_UP, NUM_INPUTS };
  INPUT inputs[NUM_INPUTS];
  inputs[MOUSE_DOWN].type = INPUT_MOUSE;
  inputs[MOUSE_DOWN].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
  inputs[MOUSE_UP].type = INPUT_MOUSE;
  inputs[MOUSE_UP].mi.dwFlags = MOUSEEVENTF_LEFTUP;
  SendInput(NUM_INPUTS, inputs, sizeof(inputs));
}