# Seguridad-de-Datos2026
Mi repositorio sobre la materia Seguridad de Datos con Tuxtter
# Brian Josep Pech Hernandez


# 🔐 Seguridad de Datos – Redes, OSI, TCP/IP y Hacking

## 📡 Modelo OSI vs TCP/IP

| Capa OSI | Nombre | TCP/IP | Función | Ejemplos |
|--------|--------|--------|--------|---------|
| 7 | Aplicación | Aplicación | Interacción con el usuario | Gmail, URLs, HTTP |
| 6 | Presentación | Aplicación | Formato, cifrado y compresión | SSL/TLS |
| 5 | Sesión | Aplicación | Control de sesiones | Active Directory, VoIP |
| 4 | Transporte | Transporte | Puertos y control de flujo | TCP, UDP |
| 3 | Red | Red | Direccionamiento lógico | IP Address |
| 2 | Enlace de datos | Enlace de datos | Direccionamiento físico | MAC Address |
| 1 | Física | Física | Transmisión de bits | Cable, fibra |

---

## 🧱 Capa de Enlace de Datos (Capa 2)

### MAC Address
- Dirección física única del dispositivo.
- Utilizada por switches para reenviar tráfico.
- No es enrutable.

### MAC Address Spoofing
Ataque que consiste en **suplantar una MAC Address** para:
- Evadir controles de acceso
- Interceptar tráfico
- Realizar ataques Man-in-the-Middle

### Switches y Seguridad
- El switch solo **conmuta tráfico**, no analiza IP.
- Dos MAC en puertos distintos no generan alerta por defecto.
- Con **802.1X**, el puerto intruso es bloqueado.

### Poisoning
- ARP Poisoning
- DNS Poisoning
- DHCP Poisoning

---

## 🌐 Capa de Red (Capa 3)

### Direcciones Lógicas (IP Address)
Permiten identificar dispositivos dentro de una red.

#### Tipos de direcciones:
- Direcciones de archivos
- Direcciones de correo electrónico
- Direcciones web
- Direcciones de telefonía IP

### Notación Decimal con Puntos
Ejemplo:
192.168.1.1

📌 El switch **no trabaja con IP**, solo con MAC.

---

## 🚚 Capa de Transporte (Capa 4)

### Puertos
- Existen **65,536 puertos**
- Identifican servicios y aplicaciones

| Puerto | Servicio |
|------|--------|
| 80 | HTTP |
| 443 | HTTPS |
| 22 | SSH |
| 21 | FTP |
| 25 | SMTP |
| 53 | DNS |
| 110 | POP3 |
| 143 | IMAP |
| 3306 | MySQL |
| 1433 | SQL Server |
| 3389 | RDP |

---

## 🔁 TCP vs UDP

| TCP | UDP |
|----|----|
| Orientado a conexión | No orientado a conexión |
| 3-Way Handshake | Sin handshake |
| Control de errores | Sin control de errores |
| Más seguro | Más rápido |

### 3-Way Handshake
1. SYN  
2. SYN-ACK  
3. ACK  

---

## 🔍 Port Scanning

### Definición
Proceso para identificar **puertos abiertos y servicios activos**.

### Herramientas
- **Nmap**
- Netcat
- Masscan

📌 Se realiza durante la **fase de reconocimiento**.

---

## 🧪 Identificación de Servicios

### Banner Grabbing
Técnica para obtener información del servicio:
- Tipo
- Versión
- Sistema operativo

⚠️ La exposición del banner incrementa el riesgo de ataque.

---

## 🧨 Vulnerabilidades

### Evaluación de riesgos
- Servicios expuestos
- Credenciales débiles
- Falta de parches
- Nivel crítico (1–10)

### Acciones de mitigación
- Parchar servicios
- Deshabilitar servicios innecesarios
- Firewall
- Segmentación de red

---

## 🌎 Servicios Expuestos en Internet

### Shodan
Motor de búsqueda para dispositivos conectados a Internet:
- Cámaras
- Routers
- Servidores
- IoT

---

## 🧠 Tipos de Hackers

### 🟢 White Hat
- Hackers éticos
- Trabajan con autorización
- Realizan auditorías y pentesting

### 🔴 Black Hat
- Hackers maliciosos
- Acceso no autorizado
- Robo de información
- Malware y ransomware

### ⚪ Gray Hat
- Intermedio entre White y Black Hat
- Acceden sin permiso pero no siempre con fines maliciosos

### 🟡 Script Kiddie
- Uso de herramientas sin entenderlas
- Bajo nivel técnico
- Alto riesgo por errores

### 🔵 Hacktivista
- Motivación ideológica o política
- Ataques a gobiernos o empresas

### 🟣 Insider
- Empleado o ex empleado
- Acceso legítimo
- Alta peligrosidad

---

## 🧑‍💻 Pentesting

### Tipos de pruebas
- **Caja Blanca**: acceso total
- **Caja Negra**: sin información previa
- **Caja Gris**: acceso parcial

### Fases
1. Reconocimiento
2. Footprinting
3. Network Mapping
4. Identificación de servicios
5. Análisis de vulnerabilidades
6. Obtención de acceso
7. Escalada de privilegios
8. Daisy Chaining

---

## 🧪 Plataformas de Práctica

| Plataforma | Uso |
|----------|----|
| Hack The Box | Laboratorios avanzados |
| TryHackMe | Aprendizaje guiado |
| VulnHub | Máquinas vulnerables |
| Metasploitable2 | Pruebas locales |
| HackerOne | Bug bounty |

---

## 📊 SIEM (Security Information and Event Management)

- Centraliza logs
- Detecta incidentes
- Correlación de eventos
- Respuesta ante ataques

---

## 🧾 Conceptos Clave

- Flaw: falla de diseño
- Exploit: código que aprovecha una vulnerabilidad
- Payload: acción ejecutada tras explotar
- Patch: corrección de seguridad
- Zero-Day: vulnerabilidad sin parche

---
# 🔐 Ataques por Capa del Modelo OSI

El modelo OSI permite clasificar **ataques de seguridad** según la capa donde actúan.  
Esto facilita su análisis, detección y mitigación.

---

## 🧱 Capa 1 – Física

### Descripción
Transmisión de bits a través de medios físicos.

### Ataques comunes
- 🔌 Desconexión de cables
- 💥 Daño físico a infraestructura
- 📡 Interferencia electromagnética
- 🕵️ Intercepción física (wiretapping)

### Riesgos
- Interrupción total del servicio
- Pérdida de disponibilidad

### Medidas de seguridad
- Control de acceso físico
- Cámaras y vigilancia
- Cableado protegido
- UPS y redundancia eléctrica

---

## 🔗 Capa 2 – Enlace de Datos

### Descripción
Comunicación entre dispositivos dentro de la misma red local.

### Ataques comunes
- MAC Address Spoofing
- ARP Poisoning
- VLAN Hopping
- DHCP Starvation
- STP Manipulation

### Riesgos
- Man-in-the-Middle
- Intercepción de tráfico
- Redireccionamiento de paquetes

### Medidas de seguridad
- 802.1X
- Port Security
- Dynamic ARP Inspection
- VLANs bien segmentadas

---

## 🌐 Capa 3 – Red

### Descripción
Direccionamiento lógico y ruteo de paquetes.

### Ataques comunes
- IP Spoofing
- ICMP Flood
- Routing Table Poisoning
- Smurf Attack

### Riesgos
- Denegación de servicio (DoS)
- Suplantación de identidad
- Desvío de tráfico

### Medidas de seguridad
- Firewalls
- ACLs
- Filtrado ICMP
- IDS/IPS

---

## 🚚 Capa 4 – Transporte

### Descripción
Control de puertos y comunicación extremo a extremo.

### Ataques comunes
- Port Scanning
- SYN Flood
- UDP Flood
- Session Hijacking

### Riesgos
- Saturación de servicios
- Acceso no autorizado
- Caída del sistema

### Medidas de seguridad
- Firewalls con estado
- Rate limiting
- IDS/IPS
- Cierre de puertos innecesarios

---

## 🔁 Capa 5 – Sesión

### Descripción
Establece, mantiene y finaliza sesiones.

### Ataques comunes
- Session Hijacking
- Session Fixation
- Replay Attacks

### Riesgos
- Secuestro de sesión
- Acceso a cuentas legítimas

### Medidas de seguridad
- Tokens seguros
- Expiración de sesiones
- Reautenticación
- HTTPS

---

## 🎭 Capa 6 – Presentación

### Descripción
Formato, cifrado y compresión de datos.

### Ataques comunes
- SSL Stripping
- Weak Encryption
- Man-in-the-Middle (MITM)

### Riesgos
- Robo de información sensible
- Datos en texto plano

### Medidas de seguridad
- TLS fuerte
- Certificados válidos
- Cifrado de extremo a extremo

---

## 🌍 Capa 7 – Aplicación

### Descripción
Interacción directa con el usuario y aplicaciones.

### Ataques comunes
- SQL Injection
- XSS (Cross-Site Scripting)
- CSRF
- Command Injection
- File Inclusion
- Brute Force

### Riesgos
- Robo de información
- Escalada de privilegios
- Compromiso total del sistema

### Medidas de seguridad
- Validación de entradas
- Autenticación fuerte
- WAF
- Parcheo continuo

---

## 🧠 Relación Ataque – Capa OSI

| Ataque | Capa |
|------|------|
| MAC Spoofing | Capa 2 |
| ARP Poisoning | Capa 2 |
| IP Spoofing | Capa 3 |
| Port Scanning | Capa 4 |
| Session Hijacking | Capa 5 |
| SSL Stripping | Capa 6 |
| SQL Injection | Capa 7 |

---

## 📌 Conclusión

Clasificar ataques por capa OSI:
- Facilita la detección
- Mejora la defensa
- Ayuda en auditorías y pentesting
- Permite aplicar controles específicos

---

## 🔐 Frase clave
> *"Cada capa del modelo OSI tiene su propia superficie de ataque."*

---
