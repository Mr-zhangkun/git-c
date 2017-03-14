#include <stdio.h>

#define FRZZ_PT 32.0
#define SCALE_FACTOR (5.0 / 9.0)
int main(int argc, char const *argv[]) {
  float fahrenheit, celsius;
  printf("Enter Fahrenheit temperature: " );
  scanf("%f",&fahrenheit );
  celsius = (fahrenheit - FRZZ_PT) * SCALE_FACTOR;
  printf("Cwlsius equivalent: %.1f\n", celsius );
  return 0;
}
