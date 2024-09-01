
/*************************************************************
  Download latest ERa library here:
    https://github.com/eoh-jsc/era-lib/releases/latest
    https://www.arduino.cc/reference/en/libraries/era
    https://registry.platformio.org/libraries/eoh-ltd/ERa/installation

    ERa website:                https://e-ra.io
    ERa blog:                   https://iotasia.org
    ERa forum:                  https://forum.eoh.io
    Follow us:                  https://www.fb.com/EoHPlatform
 *************************************************************/

// Enable debug console
// Set CORE_DEBUG_LEVEL = 3 first
// #define ERA_DEBUG

#define DEFAULT_MQTT_HOST "mqtt1.eoh.io"

// You should get Auth Token in the ERa App or ERa Dashboard
#define ERA_AUTH_TOKEN "ab6590bf-024e-4b2c-8c6e-3ed26a5fcce9"

#include <Arduino.h>
#include <ERa.hpp>
#include <ERa/ERaTimer.hpp>

const char ssid[] = "Hoang Phuc";
const char pass[] = "0906382269";

ERaTimer timer;
ERA_WRITE(V0)
{
  int value = param.getInt();
  digitalWrite(2 , value);
  ERa.virtualWrite(V0,digitalRead(2));
}
/* This function print uptime every second */
void timerEvent() {
    ERA_LOG("Timer", "Uptime: %d", ERaMillis() / 1000L);
}

void setup() {
    /* Setup debug console */
    Serial.begin(9600);

    ERa.begin(ssid, pass);

    /* Setup timer called function every second */
    timer.setInterval(1000L, timerEvent);
    pinMode(2 , OUTPUT);
}

void loop() {
    ERa.run();
    timer.run();
}

