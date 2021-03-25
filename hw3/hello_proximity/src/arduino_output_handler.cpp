/* Copyright 2019 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#include <Arduino_APDS9960.h>

#include "output_handler.h"

#include "Arduino.h"
#include "constants.h"

// The pin of the Arduino's built-in LED
int led = LED_BUILTIN;

// Track whether the function has run at least once
bool initialized = false;

// Animates a dot across the screen to represent the current x and y values
void HandleOutput(tflite::ErrorReporter* error_reporter, float x_value, float y_value) {
  
  // static, cuz need variable to carry its value over function calls.
  static bool ledFlash = true;

  // checking if any obejct is near
  // if we arent running the led (because hand is near) then
  // set the y value to -1 which will turn off the led
  if (!ledFlash) {
    y_value = -1;
  }

  // Do this only once
  if (!initialized) {
    // Set the LED pin to output
    pinMode(led, OUTPUT);
    initialized = true;
  }

  // Calculate the brightness of the LED such that y=-1 is fully off
  // and y=1 is fully on. The LED's brightness can range from 0-255.
  int brightness = (int)(127.5f * (y_value + 1));

  // check if a proximity reading is available
  if (APDS.proximityAvailable()) {
    // read the proximity
    // - 0   => close
    // - 255 => far
    // - -1  => error
    int proximity = APDS.readProximity();

    if (proximity < 100) {
      ledFlash = false;
      // print value to the Serial Monitor
      Serial.print("[Objects Detected]");
      Serial.print(" -- Brightness: ");
      Serial.print(brightness);
      Serial.print(" -- Proximity: ");
      Serial.print(proximity);
      Serial.print("\n");

    } else {
      ledFlash = true;
      // print value to the Serial Monitor
      Serial.print("[Nothing Detected]");
      Serial.print(" -- Brightness: ");
      Serial.print(brightness);
      Serial.print(" -- Proximity: ");
      Serial.print(proximity);
      Serial.print("\n");

    }
  }

  // Set the brightness of the LED. If the specified pin does not support PWM,
  // this will result in the LED being on when y > 127, off otherwise.
  analogWrite(led, brightness);

}