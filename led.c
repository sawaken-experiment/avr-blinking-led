#include <avr/io.h>

unsigned int B10000000 = 0x80; // 0b10000000 = 0x80

void sleep() {
  unsigned int i, j;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 10000; j++);
  }
}

int main() {
  unsigned int i, j;

  DDRD = B10000000; // DDR = Data Direction Registor. PD7のみ出力にする.
  PORTD = B10000000; //PD7 = Hにする.

  while(1) {
    PORTD ^= B10000000; // PD7の値を反転する.
    sleep();
  }
}
