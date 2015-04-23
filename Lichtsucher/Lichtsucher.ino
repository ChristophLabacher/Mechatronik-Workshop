class Motor	{
  public:
    Motor(int _minPin = 0, int _maxPin = 0, int _min = 0, int _max = 100, int _input = A1);
    void move(int _direction);
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

void Motor::move(int _direction)	{
  if (_direction < 0)  {
    int pin = this->minPin;
    int min = this->min;
    boolean break_ = false;

    while (break_ == false)  {
      digitalWrite(pin, HIGH);

      if (this->readPosition() <= min)  {
        break_ = true;
      }
    }

    digitalWrite(pin, LOW);

  } else if (_direction > 0) {
    int pin = this->maxPin;
    int max = this->max;
    boolean break_ = false;

    while (break_ == false)  {
      digitalWrite(pin, HIGH);

      if (this->readPosition() >= max)  {
        break_ = true;
      }
    }

    digitalWrite(pin, LOW);

  } else  {
    Serial.println("Only -1 or 1 are values that work");
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
Motor dreher(9, 8, 20, 400, A4);

// VERBINDUNG
Motor verbindung(7, 6, 320, 490, A3);

// ARM
Motor arm(5, 4, 240, 500, A2);

// KIPPER
Motor kipper(2, 3, 280, 850, A1);

// GREIFER
//Motor greifer(0, 1, 658, 357, A0);

////////////////////////////////////////////////////////////////////////////////////////////////

void setup() {
  reset();
  Serial.begin(9600);
  delay(1000);
  kipper.move(-1);

}

void loop () {
  //Serial.println(kipper.readPosition());
  //int light = analogRead(A5);

  // Serial.println(dreher.readPosition());

}
