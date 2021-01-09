#define PIN_IN1 4
#define PIN_IN2 5
#define PIN_VREF 3 // PWM

int BUTTON = 8; // タクトスイッチからの入力を8ピンに割り当て
int val = 0;
int old_val = 0;
int state = 0;

void setup()
{
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP); // タクトスイッチに繋いだピンを入力に設定
  Serial.begin(9600);
}

void loop()
{

  val = digitalRead(BUTTON);
  Serial.println(val);
  //valの値の変化をチェック
  if ((val == HIGH) && (old_val == LOW))
  {
    state = 1 - state;
    delay(10); //ハウジング対策
  }
  old_val = val;
  if (state == 1)
  {
    //前進
    Serial.println("forward!");
    digitalWrite(PIN_IN1, HIGH);
    digitalWrite(PIN_IN2, LOW);
  }
  else
  {
    //後進
    Serial.println("back!");
    // 逆回転
    digitalWrite(PIN_IN1, LOW);
    digitalWrite(PIN_IN2, HIGH);
  }
}

//void loop(){
//
//    // モーターの回転速度を中間にする
//    analogWrite(PIN_VREF,127);
//
//    if(digitalRead(INPUT_PIN) == HIGH){ // 入力ピン(タクトスイッチ)の状態を読み取る
//      Serial.println("forward!");
//      // 回転
//      digitalWrite(PIN_IN1,HIGH);
//      digitalWrite(PIN_IN2,LOW);
//    } else {
//      Serial.println("back!");
//      // 逆回転
//      digitalWrite(PIN_IN1,LOW);
//      digitalWrite(PIN_IN2,HIGH);
//    }

//
//    // 回転
//    digitalWrite(PIN_IN1,HIGH);
//    digitalWrite(PIN_IN2,LOW);
//    delay(5000);
//
//    // ブレーキ
//    digitalWrite(PIN_IN1,HIGH);
//    digitalWrite(PIN_IN2,HIGH);
//
//    // 逆回転
//    digitalWrite(PIN_IN1,LOW);
//    digitalWrite(PIN_IN2,HIGH);
//    delay(5000);
//
//    // ブレーキ
//    digitalWrite(PIN_IN1,HIGH);
//    digitalWrite(PIN_IN2,HIGH);
//    delay(2000);
//
//    // モーターの回転速度を最大にする
//    analogWrite(PIN_VREF,255);
//
//    // 逆回転　
//    digitalWrite(PIN_IN1,LOW);
//    digitalWrite(PIN_IN2,HIGH);
//    delay(5000);
//
//    // ストップ
//    digitalWrite(PIN_IN1,LOW);
//    digitalWrite(PIN_IN2,LOW);
//    delay(2000);
//}
