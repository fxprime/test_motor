/**
 * ArduinoNa
 * Test motor 2channel
 */

#include "motor.h"

void setup() {
  Serial.begin(115200);
  motor_init();
}

void loop() {

  //ขับมอเตอร์ไปข้างหน้า
  motor_cmd(1,1);

  //ใส่ (1,0) เพื่อขับมอเตอร์ซ้ายอย่างเดียว
  //ใส่ (0,1) เพื่อขับมอเตอร์ขวาอย่างเดียว
  //ใส่ (-1,-1) เพื่อถอยหลังทั้งสองข้าง
  //ใส่ (0.5, 0.5) เพื่อขับมอเตอร์ไปข้างหน้าทั้งสองข้างด้วยความเร็วครึ่งเดียว
}
