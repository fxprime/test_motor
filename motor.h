//ขาสัญญาณมอเตอร์ซ้าย
uint8_t MLftDirAPin = 9;
uint8_t MLftDirBPin = 8;
uint8_t MLftSpdPin = 7;
bool  MLftRev = false; //กลับทิศทาง

//ขาสัญญาณมอเตอร์ขวา
uint8_t MRgtDirAPin = 10;
uint8_t MRgtDirBPin = 11;
uint8_t MRgtSpdPin = 12;
bool  MRgtRev = true; //กลับทิศทาง


//ฟังก์ชันดูเครื่องหมาย >0 ให้ค่าเป็น 1 , <0 ให้ค่าเป็น -1
template <typename type>
type sign(type value) {
    return type((value>0)-(value<0));
}

//ฟังก์ชันเริ่มการตั้งค่ามอเตอร์ ให้รันใน Setup()
void motor_init() {
    pinMode(MLftDirAPin, OUTPUT);
    pinMode(MLftDirBPin, OUTPUT);
    pinMode(MLftSpdPin, OUTPUT);
    pinMode(MRgtDirAPin, OUTPUT);
    pinMode(MRgtDirBPin, OUTPUT);
    pinMode(MRgtSpdPin, OUTPUT);
    Serial.println("Motor inited");
}

/**
 * ฟังก์ชันขับมอเตอร์โดยดูจากความเร็วที่ให้มา หาก speed เป็น + ให้ทิศทางไปข้างหน้า - คือถอยหลัง 0 คือหยุด
 * โดยความเร็วมีค่าตั้งแต่ -1 ถึง 1 สำหรับแต่ละล้อ
 * @param leftspd [-1.0, 1.0]
 * @param rightspd [-1.0, 1.0]
 */
void motor_cmd(float leftspd, float rightspd) {

    //Check direction from spd >0 forward, <0 backward, 0 stop
    digitalWrite( MLftDirAPin, (MLftRev ? sign(leftspd)>0 : sign(leftspd)<0) );
    digitalWrite( MLftDirBPin, (MLftRev ? sign(leftspd)<0 : sign(leftspd)>0));
    digitalWrite( MRgtDirAPin, (MRgtRev ? sign(rightspd)>0 : sign(rightspd)<0) );
    digitalWrite( MRgtDirBPin, (MRgtRev ? sign(rightspd)<0 : sign(rightspd)>0) );

    float Lout = constrain( fabs(leftspd*1000), 0, 1000)/1000.0;
    float Rout = constrain( fabs(rightspd*1000), 0, 1000)/1000.0;

    analogWrite(MLftSpdPin, Lout*255.0);
    analogWrite(MRgtSpdPin, Rout*255.0);
}
