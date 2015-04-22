class Motor	{
public: 
  Motor(int _minPin = 0, int _maxPin = 0, int _min = 0, int _max = 100, int _input = A1);
  void move(int _steps);
  int readPosition();

protected:
  int minPin;
  int maxPin;
  int min;
  int max;
  int input;
  float stepSize;
  int currentStep;
};

Motor::Motor(int _minPin, int _maxPin, int _min, int _max, int _input)	{
  this->minPin = _minPin;
  this->maxPin = _maxPin;
  this->min = _min;
  this->max = _max;
  this->input = _input;

  float stepSize_ = (_max - _min) * 0.01;
  this->stepSize = abs(stepSize_);
}

void Motor::move(int _steps)	{
  int stepCount = abs(_steps);
  int stepDirection = 0;
  int pin = 0;

  if (_steps < 0)  {
    stepDirection = -1;
    pin = this->minPin;
  } 
  else {
    stepDirection = 1;
    pin = this->maxPin;
  }

  for (int i = 0; i < stepCount; i++)  {
    int currentStep = map(this->readPosition(), this->min, this->max, 0, 100);

    if (currentStep + stepDirection <= 100 && currentStep + stepDirection >= 0)  {

      Serial.print("currentStep: ");
      Serial.println(currentStep);
      Serial.print("stepSize: ");
      Serial.println(stepSize);

      digitalWrite(pin, HIGH);
      delay(100);
      digitalWrite(pin, LOW);

      float currentPos = this->readPosition();
      float targetPos = currentPos + (this->stepSize * stepDirection); 
    }
  }
}

int Motor::readPosition()	{
  return analogRead(this->input);
}

void reset()	{
  pinMode(9, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(0, OUTPUT);

  // Reset
  digitalWrite(9, LOW);
  digitalWrite(8, LOW);
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
  digitalWrite(3, LOW);
  digitalWrite(2, LOW);
  digitalWrite(1, LOW);
  digitalWrite(0, LOW);
}

// DREHER
Motor dreher(8, 9, 40, 619, A4);

// VERBINDUNG
Motor verbindung(6, 7, 555, 328, A3);

// ARM
Motor arm(4, 5, 767, 213, A2);

// KIPPER
Motor kipper(2, 3, 93, 990, A1);

// GREIFER
Motor greifer(0, 1, 658, 357, A0);

////////////////////////////////////////////////////////////////////////////////////////////////

void setup(){
  reset();
  Serial.begin(9600);
  delay(1000);
  dreher.move(50);
  //Serial.println(dreher.readPosition());
  //
   digitalWrite(9, HIGH);
    delay(2000);
    digitalWrite(9, LOW);

}

void loop () {
  //int light = analogRead(A5);
  //Serial.println(light);

}




















