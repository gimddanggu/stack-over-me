#include "HUSKYLENS.h"
#include <SoftwareSerial.h>
HUSKYLENS huskylens;
SoftwareSerial mySerial(10, 11); // RX, TX

// 물건 정보를 저장할 구조체
typedef struct {
  int tag;      // 1, 2, 3
  int color;    // 1, 2, 3, 4 (빨, 파, 초, 노)
  int shape;    // 1, 2, 3, 4, 5, 6 (원기둥, 삼각기둥, 육각기둥, 사각뿔, 정육면체, 원뿔)
} ObjectInfo;

// 양품 정보를 저장할 구조체
struct Standard {
  int color;
  int shape;
};

// 양품 정보
Standard goodSpec[4] = {
  {0, 0}, {2, 1}, {3, 3}, {4, 5}
};


ObjectInfo detectedObject;
protocolAlgorithm currentAlgorithm;  // 현재 모드 저장

void printResult(HUSKYLENSResult result);
void processDetectionStep(ObjectInfo& obj);
bool isQualified(ObjectInfo obj);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
    mySerial.begin(9600);
    // 초기값 while문 안에 넣어서 오류 발생했었다.
    currentAlgorithm = ALGORITHM_TAG_RECOGNITION;
    while (!huskylens.begin(mySerial))
    {
      Serial.println(F("Begin failed!"));
      Serial.println(F("1.Please recheck the \"Protocol Type\" in HUSKYLENS (General Settings>>Protocol Type>>Serial 9600)"));
      Serial.println(F("2.Please recheck the connection."));
      delay(100);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!huskylens.request()) Serial.println(F("Fail to request data from HUSKYLENS, recheck the connection!"));
  else if(!huskylens.isLearned()) Serial.println(F("Nothing learned, press learn button on HUSKYLENS to learn one!"));
  // 버퍼에 남아있는 블록과 화살표의 수
  else if(!huskylens.available()) Serial.println(F("No block or arrow appears on the screen!"));
  else
  {
    Serial.println(F("###########"));
    while (huskylens.available())
    {
      // Serial.println(currentAlgorithm);
      // 블록이나 화살표를 읽어옴
      processDetectionStep(detectedObject); // 화면전환하며 상태를 구조체에 저장
      // if(isQualified(detectedObject)) Serial.println(String()+F("Block:xCenter=")+detectedObject.color);
      //else Serial.println("fail");
      // printResult(result);
    }    
  }
}

void printResult(HUSKYLENSResult result){
    // 블럭이 존재한다면, 위치, id 반환
    if (result.command == COMMAND_RETURN_BLOCK){
        Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);
    }
    else if (result.command == COMMAND_RETURN_ARROW){
        Serial.println(String()+F("Arrow:xOrigin=")+result.xOrigin+F(",yOrigin=")+result.yOrigin+F(",xTarget=")+result.xTarget+F(",yTarget=")+result.yTarget+F(",ID=")+result.ID);
    }
    else{
        Serial.println("Object unknown!");
    }
}


void processDetectionStep(ObjectInfo& obj) {
  if (currentAlgorithm == ALGORITHM_TAG_RECOGNITION) {
    Serial.println(String()+String()+F("currentMode: ALGORITHM_TAG_RECOGNITION"));
    HUSKYLENSResult result = huskylens.getBlockLearned(0);
    obj.tag = result.ID;
    huskylens.writeAlgorithm(ALGORITHM_COLOR_RECOGNITION);
    Serial.println(String()+F("Block:xCenter=")+result.xCenter+F(",yCenter=")+result.yCenter+F(",width=")+result.width+F(",height=")+result.height+F(",ID=")+result.ID);
    Serial.println(String()+F("TagNum")+obj.tag);
    currentAlgorithm = ALGORITHM_COLOR_RECOGNITION;
  }
  else if (currentAlgorithm == ALGORITHM_COLOR_RECOGNITION) {
    Serial.println(String()+F("currentMode: ALGORITHM_COLOR_RECOGNITION"));
    HUSKYLENSResult result = huskylens.getBlockLearned(0);
    // obj.color = result.ID;
    huskylens.writeAlgorithm(ALGORITHM_OBJECT_CLASSIFICATION);
    currentAlgorithm = ALGORITHM_OBJECT_CLASSIFICATION;
  }
  // 물체인식은 모드 전환 시 데이터 초기화 이슈가 있으므로 일단 제외
  /*else if (currentAlgorithm == ALGORITHM_OBJECT_CLASSIFICATION) {
    HUSKYLENSResult result = huskylens.getBlockLearned(0);
    obj.shape = result.ID;
    huskylens.writeAlgorithm(ALGORITHM_TAG_RECOGNITION);
    currentAlgorithm = ALGORITHM_TAG_RECOGNITION;
  }*/
  delay(2000);
}
// 구조체에 정보가 다 담김

bool isQualified(ObjectInfo obj)
{
  return obj.color == goodSpec[obj.tag].color && obj.shape == goodSpec[obj.tag].shape;
}


