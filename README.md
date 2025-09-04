
# 该项目可以让为直流电机设计的力回馈模拟器可以控制步进电机
使用一个中间件将RPWM和LPWM转为步进电机控制信号
# 支持设备
-Arduino Uno
-Arduino Nano
-Arduino Mega2560

# 接线
-输入
-A0 RPWM
-A1 LPWM(方向错误时将RPWM LPWM调转）

输出
-9  PUL
-10 DIR
-11 ENA
