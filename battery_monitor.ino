// 电量监测与低电报警
#define BATTERY_PIN 36  // ADC1_CH0
#define LOW_VOLTAGE 10.5  // 10.5V 触发报警

float readBatteryVoltage() {
  int adcValue = analogRead(BATTERY_PIN);
  float voltage = (adcValue / 4095.0) * 3.3 * (10000 + 5100) / 5100; // 15.1kΩ 分压
  return voltage * 3.5; // 12V ≈ 3.5x 放大
}

void checkBattery() {
  float voltage = readBatteryVoltage();
  Serial.print("Battery Voltage: ");
  Serial.print(voltage);
  Serial.println("V");

  if (voltage < LOW_VOLTAGE) {
    Serial.println("⚠️ Low Battery! Please recharge!");
    // 可触发蜂鸣器或发送报警信号
  }
}

void loop() {
  checkBattery();
  delay(5000);
}