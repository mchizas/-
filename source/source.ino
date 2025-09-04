/*RPWM和LPWM转PUL/DIR/ENA控制器





*/
#define RPWM_PIN A0    // PWM输入
#define LPWM_PIN A1    // PWM输入
#define PUL_PIN 9       //PUL输出
#define DIR_PIN 10      //PUL输出
#define ENA_PIN 11      //ENA输出

// 阈值设置
#define THRESHOLD 50   // 信号阈值

void setup() {
  pinMode(PUL_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(ENA_PIN, OUTPUT);
  digitalWrite(ENA_PIN, HIGH); // 初始状态: 电机禁用 ENA高电平
}

void loop() {
  // 读取信号
  int rpwm = analogRead(RPWM_PIN);
  int lpwm = analogRead(LPWM_PIN);
  
  // 确定电机状态
  if (rpwm > THRESHOLD || lpwm > THRESHOLD) {
    digitalWrite(ENA_PIN, LOW); // 电机使能
    
    // 设置方向
    if (rpwm > lpwm) {
      digitalWrite(DIR_PIN, HIGH); // 正向
    } else {
      digitalWrite(DIR_PIN, LOW);  // 反向
    }
    
    // 生成脉冲
    digitalWrite(PUL_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(PUL_PIN, LOW);
    
    // 根据信号强度调整脉冲间隔
    int max_signal = max(rpwm, lpwm);
    int delay_time = map(max_signal, THRESHOLD, 1023, 2000, 200);
    delayMicroseconds(constrain(delay_time, 200, 2000));
  } else {
    digitalWrite(ENA_PIN, HIGH); // 电机禁用
    delay(10); // 当电机停止时减少循环频率
  }
}