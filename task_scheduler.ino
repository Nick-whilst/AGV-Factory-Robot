// AGV 任务调度器 - 状态机模式
// 适用于工厂物流自动往返搬运

enum State {
  IDLE,
  MOVING_TO_POINT,
  PICKING_UP,
  RETURNING_HOME,
  ERROR
};

State currentState = IDLE;
String targetPoint = "";
String taskQueue[] = {"A1", "B2", "C3"};
int queueIndex = 0;

void setup() {
  Serial.begin(115200);
  SerialBT.begin("AGV_Controller");
}

void loop() {
  switch (currentState) {
    case IDLE:
      if (queueIndex < 3) {
        targetPoint = taskQueue[queueIndex];
        Serial.println("Starting task: " + targetPoint);
        currentState = MOVING_TO_POINT;
      }
      break;

    case MOVING_TO_POINT:
      SerialBT.println("GO:" + targetPoint);
      delay(2000); // 模拟移动时间
      Serial.println("Arrived at " + targetPoint);
      currentState = PICKING_UP;
      break;

    case PICKING_UP:
      Serial.println("Picking up...");
      delay(3000); // 模拟搬运时间
      Serial.println("Item picked up.");
      currentState = RETURNING_HOME;
      break;

    case RETURNING_HOME:
      SerialBT.println("GO:HOME");
      delay(2000);
      Serial.println("Returned to base.");
      queueIndex++;
      currentState = IDLE;
      break;

    case ERROR:
      Serial.println("Error: Task failed!");
      currentState = IDLE;
      break;
  }

  delay(100);
}