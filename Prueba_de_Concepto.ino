#include <DigiKeyboard.h>

void setup() {
  DigiKeyboard.delay(3000);

  // Cambiar a teclado EN (NO SE QUITA)
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT);
  DigiKeyboard.delay(1500);

  // Win + R
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(1000);

  // Abrir CMD
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(3000);

  // Ir al Escritorio
  DigiKeyboard.print("cd %USERPROFILE%\\Desktop");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(2000);

  // Descargar imagen
  DigiKeyboard.print(
    "curl https://i.pinimg.com/236x/b0/f0/52/b0f0524e80ed52cf5a38d0fa93035a95.jpg -o gato.jpg"
  );
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(5000);

  // Abrir la imagen 3 veces
  DigiKeyboard.print("for /L %i in (1,1,3) do start \"\" gato.jpg");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
}

void loop() {}
