#include "HUSKYLENS.h"
#define HL Serial1

// 물건 정보를 저장할 구조체
typedef struct {
  int tag;      // 1, 2, 3
  int color;    // 1, 2, 3(초, 파, 빨)
  int shape;    // 1, 2, 3 (정육면체, 삼각기둥, 원기둥)
} ObjectInfo;

// 양품 정보를 저장할 구조체
struct Standard {
  int tag;
  int color;
  int shape;
};

// 양품 정보
Standard goodSpec[4] = {
  {1, 2, 3}, {2, 1, 1}, {3, 3, 2}
}; 
// 1: 파랑, 원기둥
// 2: 초록, 정육면체
// 3: 빨강, 삼각기둥

const int GOOD_SPEC_COUNT = sizeof(goodSpec) / sizeof(goodSpec[0]);

// 매핑 함수
const char* tagName(int tag) {
  switch (tag) {
    case 1: return "품목1";
    case 2: return "품목2";
    case 3: return "품목3";
  }
}
const char* colorName(int color) {
  switch (color) {
    case 1: return "파랑";
    case 2: return "초록";
    case 3: return "빨강";
  }
}
const char* shapeName(int shape) {
  switch (shape) {
    case 1: return "원기둥";
    case 2: return "정육면체";
    case 3: return "삼각기둥";
  }
}

// 규격 조회
const Standard* findStandardByTag(int tag) {
  for (int i = 0; i < GOOD_SPEC_COUNT; ++i) {
    if (goodSpec[i].tag == tag)
  }
  return nullptr;
}

// 규격 판정
bool isGood(const ObjectInfo& obj) {
  const Standard* s = findStandardByTag(obj.tag); // 해당 태그의 양품 정보 가져옴
  if (!s) return false;
  return (obj.color == s->color) && (obj.shape == s->shape);
}

HUSKYLENS huskylens;
protocolAlgorithm currentAlgorithm;
ObjectInfo detectedObject;
bool scanning = false;

// 화면에 블럭있으면 
bool isBlock() {
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
  // 시리얼 입력 받았을 때 (이후에 적외선 센서로 교체)
  if (Serial.available() > 0) {
    char input = Serial.read();
    Serial.print("Got: ");
    Serial.println(input);

    // 적외선 센서 입력 들어옴
    if (input == '1') {
      scanning = true;
      currentAlgorithm = ALGORITHM_TAG_RECOGNITION;
      huskylens.writeAlgorithm(currentAlgorithm);
      while(scanning) {
        delay(500);
        if (currentAlgorithm == ALGORITHM_TAG_RECOGNITION) {
          Serial.println(String()+String()+F("currentMode: ALGORITHM_TAG_RECOGNITION"));
        // 화면에 블럭있으면 처리하고 다음 화면 넘어가기
          if (isBlock()) {
            HUSKYLENSResult result = huskylens.getBlockLearned(0);
            if (result.ID > 0) {
              Serial.println(String()+F("TagNum: ") + result.ID);  
              currentAlgorithm = ALGORITHM_COLOR_RECOGNITION;
              huskylens.writeAlgorithm(currentAlgorithm);
              delay(800);
            }
          }
        }
      
        else if (currentAlgorithm == ALGORITHM_COLOR_RECOGNITION) {
          Serial.println(String()+F("currentMode: ALGORITHM_COLOR_RECOGNITION"));
          if (isBlock()) {
            HUSKYLENSResult result = huskylens.getBlockLearned(0);
            if (result.ID > 0) {
              Serial.println(String()+F("ColorNum: ") + result.ID);  
              currentAlgorithm = ALGORITHM_OBJECT_CLASSIFICATION;
              huskylens.writeAlgorithm(currentAlgorithm);
              delay(800);
            }
          }
        }
        else if (currentAlgorithm == ALGORITHM_OBJECT_CLASSIFICATION) {
          Serial.println(String()+F("currentMode: ALGORITHM_OBJECT_CLASSIFICATION"));
          if (isBlock()) {
            HUSKYLENSResult result = huskylens.getBlockLearned(0);
            if (result.ID > 0) {
              Serial.println(String()+F("ShapeNum: ") + result.ID);  
              currentAlgorithm = ALGORITHM_TAG_RECOGNITION;
              huskylens.writeAlgorithm(currentAlgorithm);
              delay(800);
              scanning = false;
            }
          }
        }

      }

      
    }
    else if (input == '0') {
      // scanning = false;
    }
  }
}