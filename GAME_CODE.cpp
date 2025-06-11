#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 1
#define DATA_PIN 23
#define CLK_PIN 18
#define CS_PIN 5

MD_MAX72XX matrix = MD_MAX72XX(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

const int JOY_X = 36;
const int JOY_Y = 39;
const int BUZZER = 15;
const int TRIG = 12;
const int ECHO = 14;

int heroX = 0, heroY = 0;
int lastDX = 0, lastDY = 0;

int tankY = 0;
bool tankDown = true;
unsigned long lastTankMove = 0;
const int tankSpeed = 300;

// Wall coordinates
bool wall[8][8] = {false};

void setup() {
  Serial.begin(115200);
  matrix.begin();
  matrix.clear();

  pinMode(BUZZER, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
}

void loop() {
  matrix.clear();

  // Read distance
  float distance = getDistance();

  // Read joystick
  int joyX = analogRead(JOY_X);
  int joyY = analogRead(JOY_Y);

  // Movement + wall check
  if (joyX < 1000) tryMove(-1, 0);
  else if (joyX > 3000) tryMove(1, 0);
  if (joyY < 1000) tryMove(0, 1);
  else if (joyY > 3000) tryMove(0, -1);

  // Wall generation if close to sensor
  if (distance < 30) generateWall();

  // Tank movement
  if (millis() - lastTankMove > tankSpeed) {
    lastTankMove = millis();
    tankY += tankDown ? 1 : -1;
    if (tankY >= 6) tankDown = false;
    else if (tankY <= 0) tankDown = true;
  }

  // Collision with tank
  for (int i = 3; i <= 4; i++) {
    for (int j = tankY; j < tankY + 2; j++) {
      if (heroX == i && heroY == j) {
        tone(BUZZER, 1000, 200);
        delay(500);
        resetGame();
      }
    }
  }

  // Victory
  if (heroX == 7 && heroY == 7) {
    tone(BUZZER, 1500, 500);
    delay(1000);
    resetGame();
  }

  // Draw tank
  for (int i = 3; i <= 4; i++)
    for (int j = tankY; j < tankY + 2; j++)
      matrix.setPoint(j, i, true);

  // Draw walls
  for (int x = 0; x < 8; x++)
    for (int y = 0; y < 8; y++)
      if (wall[x][y]) matrix.setPoint(y, x, true);

  // Draw player
  matrix.setPoint(heroY, heroX, true);

  matrix.update();
  delay(100);
}

void tryMove(int dx, int dy) {
  int newX = heroX + dx;
  int newY = heroY + dy;
  if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8) {
    if (!wall[newX][newY]) {
      heroX = newX;
      heroY = newY;
      lastDX = dx;
      lastDY = dy;
    }
  }
}

void generateWall() {
  // Clear previous walls
  memset(wall, false, sizeof(wall));

  if (lastDX != 0) {
    int wallX = heroX + (lastDX > 0 ? 1 : -1);
    if (wallX >= 0 && wallX <= 7) {
      for (int i = -1; i <= 1; i++) {
        int y = heroY + i;
        if (y >= 0 && y < 8)
          wall[wallX][y] = true;
      }
    }
  } else if (lastDY != 0) {
    int wallY = heroY + (lastDY > 0 ? 1 : -1);
    if (wallY >= 0 && wallY <= 7) {
      for (int i = -1; i <= 1; i++) {
        int x = heroX + i;
        if (x >= 0 && x < 8)
          wall[x][wallY] = true;
      }
    }
  }
}

float getDistance() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 20000);  // Timeout at 20 ms
  float distance = duration * 0.034 / 2.0;
  return distance;
}

void resetGame() {
  heroX = 0;
  heroY = 0;
  memset(wall, false, sizeof(wall));
}

