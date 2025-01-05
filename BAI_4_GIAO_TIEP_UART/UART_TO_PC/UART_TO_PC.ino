#define led 2
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  //Serial.println("Hello pc!");
  //Serial.print("I am ESP32 DEVKIT V1!\n");
  // Serial.print("This is Test!");
  // String str = "Hello pc!";
  // for(int i=0; i<str.length(); i++){
  //   Serial.write(str[i]);
  // }
  int number = 100;
  float f = 3.15;
  Serial.println("Num: " + String(number) + "\tPI: "+String(f,1));
  pinMode(led,OUTPUT);
}
void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){ //Bộ nhớ đệm UART > 0
    String key = "";
    while(Serial.available()>0){
      char c = Serial.read(); //Đọc trong bộ đệm UART
      key = key+c;
      Serial.write(c); //Truyền lên PC
      // if(c=='0'){
      //   digitalWrite(led,LOW);
      // }else if(c=='1'){
      //   digitalWrite(led,HIGH);
      // }
    }
    Serial.println("Key: "+key);
    if(key=="on") digitalWrite(led,HIGH);
    else if(key=="off") digitalWrite(led,LOW);
  }
  Serial.println("Key: "+key);
}
