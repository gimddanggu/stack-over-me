// serial 입력 받았을 때 모드 이동 처리 (기본)

#include "HUSKYLENS.h"
#define HL Serial1

HUSKYLENS huskylens;
protocolAlgorithm currentAlgorithm; 

// 화면에 블럭있으면 
bool irTrigger() {
  if (!huskylens.request()) return false;
  return huskylens.available(); // 읽을 수 있는 블럭 수 반환
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  HL.begin(9600);
  while (!huskylens.begin(HL)) { delay(100); } 
  currentAlgorithm = ALGORITHM_TAG_RECOGNITION;
  huskylens.writeAlgorithm(currentAlgorithm);
  Serial.println("HuskyLens ready.");
}

void loop() {
  // put your main code here, to run repeatedly:
  // 시리얼 입력 받았을 때
  if (Serial.available() > 0) {
    char input = Serial.read();
    Serial.print("Got: ");
    Serial.println(input);

    if (input == '1') {
      // scanning = true;
      currentAlgorithm = ALGORITHM_TAG_RECOGNITION;
      huskylens.writeAlgorithm(currentAlgorithm);
      delay(800);

      if (currentAlgorithm == ALGORITHM_TAG_RECOGNITION) {
        Serial.println(String()+String()+F("currentMode: ALGORITHM_TAG_RECOGNITION"));
        currentAlgorithm = ALGORITHM_COLOR_RECOGNITION;
        huskylens.writeAlgorithm(currentAlgorithm);
        delay(800);
      }
      if (currentAlgorithm == ALGORITHM_COLOR_RECOGNITION) {
        Serial.println(String()+F("currentMode: ALGORITHM_COLOR_RECOGNITION"));
        currentAlgorithm = ALGORITHM_OBJECT_CLASSIFICATION;
        huskylens.writeAlgorithm(currentAlgorithm);
        delay(800);
      }
      if (currentAlgorithm == ALGORITHM_OBJECT_CLASSIFICATION) {
        Serial.println(String()+F("currentMode: ALGORITHM_OBJECT_CLASSIFICATION"));
        currentAlgorithm = ALGORITHM_TAG_RECOGNITION;
        huskylens.writeAlgorithm(currentAlgorithm);
        delay(800);
        // scanning = false;
      }
    }
    else if (input == '0') {
      // scanning = false;
    }
  }
}