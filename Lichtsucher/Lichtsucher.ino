class Motor	{
public: 
  Motor(int _up = 100, int _down = 100, int _left = 100, int _right = 100, int _open = 100, int _close = 100, int _input = A10);
  void move(String _direction, int _length);
  int readPosition();

protected:
  int up;
  int down;
  int left;
  int right;
  int open;
  int close;
  int input;
};

Motor::Motor(int _up, int _down, int _left, int _right, int _open, int _close, int _input)	{
  this->up = _up;
  this->down = _down;
  this->left = _left;
  this->right = _right;
  this->open = _open;
  this->close = _close;
  this->input = _input;
}

void Motor::move(String _direction, int _length)	{
  int pin = 100;

  if (_direction == "up")	{
    pin = this->up;
  }

  if (_direction == "down")	{
    pin = this->down;
  }

  if (_direction == "left")	{
    pin = this->left;	
  }

  if (_direction == "right")	{
    pin = this->right;	
  }

  if (_direction == "open")	{
    pin = this->open;	
  }

  if (_direction == "close")	{
    pin = this->close;	
  }

  digitalWrite(pin, HIGH);
  delay(_length);
  digitalWrite(pin, LOW);
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
Motor dreher(0, 0, 8, 9, 0, 0, A4);

// VERBINDUNG
Motor verbindung(6, 7, 0, 0, 0, 0, A3);

// ARM
Motor arm(5, 4, 0, 0, 0, 0, A2);

// KIPPER
Motor kipper(3, 2, 0, 0, 0, 0, A1);

// GREIFER
Motor greifer(0, 0, 0, 0, 1, 0, A0);

////////////////////////////////////////////////////////////////////////////////////////////////

void setup(){
  reset();
  Serial.begin(9600);
  dreher.move("right",4000);
}

void loop () {
  Serial.println(dreher.readPosition());
}

