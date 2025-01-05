#include <HardwareSerial.h>

#define LED_PIN 2

HardwareSerial MySerial(0); // Sử dụng UART0

void IRAM_ATTR onUartReceive() {
    while (MySerial.available()) {
        String data = MySerial.readStringUntil('\n');
        MySerial.println(data);
        data.trim(); // Loại bỏ khoảng trắng ở đầu và cuối chuỗi

        if (data.equals("ON")) {
            digitalWrite(LED_PIN, HIGH);
        } else if (data.equals("OFF")) {
            digitalWrite(LED_PIN, LOW);
        }
    }
}

void setup() {
    pinMode(LED_PIN, OUTPUT);
    digitalWrite(LED_PIN, LOW);

    // Cấu hình UART0
    MySerial.begin(115200, SERIAL_8N1, 3, 1); // RX=3, TX=1

    MySerial.onReceive(onUartReceive); // Đăng ký hàm xử lý ngắt UART
}

void loop() {
  delay(10000);
}
