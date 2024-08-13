#include "main.h"

int main(void) {
    // Inicializa a HAL Library
    HAL_Init();

    // Inicializa o LED
    GPIO_Init();
    lcd_init(); //Configura o display LCD

    
    //lcd_texto("de Almeida Pereira");
    HAL_Delay(1);

    while (1) {
      char leitura = read_keypad();

      switch(leitura){
        case '1':
          
          lcd_texto("Ygor");
          break;
        case '2':

          lcd_texto("de Almeida Pereira");
          break;
        case 'A':

          lcd_texto("Ygor de Almeida Pereira");
          break;
        case 0:
          break;
        default:

          lcd_texto("Digite uma tecla (1, 2 ou A)");
          break;

      }
    }
}