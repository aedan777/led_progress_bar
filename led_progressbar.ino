#define POTENTIOMETR_PIN A6

#define LED_1 10
#define LED_2 9
#define LED_3 8
#define LED_4 7
#define LED_5 6
#define LED_6 5

// светодиоды и их состояния
byte led_array[][2] = {
  {LED_1, 0},
  {LED_2, 0},
  {LED_3, 0},
  {LED_4, 0},
  {LED_5, 0},
  {LED_6, 0},
};

void setup() {
  // инициализация пинов
  for (byte i = 0; i < 6; i = i + 1) {
    pinMode(led_array[i][0], OUTPUT);
  }
  // Режим визуальной диагностики перед запуском основного цикла
  // а еще, это красиво
  init_sequence();
}

void loop() {

  // Меняем значения в массиве,в зависимости от значения на потенциометре
  switch (analogRead(POTENTIOMETR_PIN)) {
    case 0 ... 169:
      {
        byte mask[6] = {1, 0, 0, 0, 0, 0};
      
        for (byte i = 0; i < 6; i = i + 1){
          led_array[i][1] = mask[i];
        }
      }
      break;
    case 170 ... 340:
       {
        byte mask[6] = {1, 1, 0, 0, 0, 0};
      
        for (byte i = 0; i < 6; i = i + 1){
          led_array[i][1] = mask[i];
        }
      }
      break;
    case 341 ... 512:
       {
        byte mask[6] = {1, 1, 1, 0, 0, 0};
      
        for (byte i = 0; i < 6; i = i + 1){
          led_array[i][1] = mask[i];
        }
      }
      break;
    case 513 ... 683:
       {
        byte mask[6] = {1, 1, 1, 1, 0, 0};
      
        for (byte i = 0; i < 6; i = i + 1){
          led_array[i][1] = mask[i];
        }
      }
      break;
    case 684 ... 853:
       {
        byte mask[6] = {1, 1, 1, 1, 1, 0};
      
        for (byte i = 0; i < 6; i = i + 1){
          led_array[i][1] = mask[i];
        }
      }
      break;
    case 854 ... 1024:
       {
        byte mask[6] = {1, 1, 1, 1, 1, 1};
      
        for (byte i = 0; i < 6; i = i + 1){
          led_array[i][1] = mask[i];
        }
      }
      break;
    
  }

  // Зажегаем светодиоды
  for (byte i = 0; i < 6; i = i + 1) {
    digitalWrite(led_array[i][0], led_array[i][1]);
  }

  // Небольшая задержка
  delay(10);

}


void init_sequence() {
  // Светодиоды загораются по одному
  for (byte i = 0; i < 6; i = i + 1) {
    digitalWrite(led_array[i][0], 1);
    delay(300);
    digitalWrite(led_array[i][0], 0);
    delay(300);
  }
  // Зажегается вся полоска
  for (byte i = 0; i < 6; i = i + 1) {
    digitalWrite(led_array[i][0], 1);
  }
  delay(500);
  // Визуальная диагностика завершена
  for (byte i = 0; i < 6; i = i + 1) {
    digitalWrite(led_array[i][0], 0);
  }
}
