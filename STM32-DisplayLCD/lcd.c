#include "lcd.h"


// Função para envio de comandos para o LCD
void lcd_command(uint8_t cmd){
  HAL_Delay(1);
  HAL_GPIO_WritePin(Data_Port,
  GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(Data_Port, cmd, GPIO_PIN_SET); // Envia comando
  HAL_Delay(1);
  HAL_GPIO_WritePin(Control_Port, RS_Pin, GPIO_PIN_RESET); // RS = 0 para comando
  HAL_GPIO_WritePin(Control_Port, RW_Pin, GPIO_PIN_RESET); // RW = 0 para escrever
  HAL_GPIO_WritePin(Control_Port, E_Pin, GPIO_PIN_SET); // E = 1
  HAL_Delay(1);
  HAL_GPIO_WritePin(Control_Port, E_Pin, GPIO_PIN_RESET); // E = 0
  HAL_Delay(1); // Espera por comando ser processado
}

// Função para envio de dados para o LCD
void lcd_data(uint8_t data) {
  HAL_Delay(1);
  HAL_GPIO_WritePin(Data_Port,
  GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5|GPIO_PIN_6|GPIO_PIN_7, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(Data_Port, data, GPIO_PIN_SET); // Envia dados
  HAL_Delay(1);
  HAL_GPIO_WritePin(Control_Port, RS_Pin, GPIO_PIN_SET); // RS = 1 para dados
  HAL_GPIO_WritePin(Control_Port, RW_Pin, GPIO_PIN_RESET); // RW = 0 para escrever
  HAL_GPIO_WritePin(Control_Port, E_Pin, GPIO_PIN_SET); // E = 1
  HAL_Delay(1);
  HAL_GPIO_WritePin(Control_Port, E_Pin, GPIO_PIN_RESET); // E = 0
  HAL_Delay(1); // Espera por dado ser processado
}

void lcd_texto (char* frase){
  short int row = 0;
  short int col = 0;
  lcd_command(0x01);
  HAL_Delay(1);
  size_t tamanho = strlen(frase);
  for (size_t i=0; i< tamanho; i++){
    uint8_t caractere = frase[i];
    lcd_goto_XY(row, col);
    lcd_data(caractere);
    col++;
    if(col==16){
      row++;
      col=0;
    }
  } 
}

//Função auxiliar que indica a linha e coluna para escrita no display LCD
void lcd_goto_XY(uint8_t row, uint8_t col) {
uint8_t pos;
if (row == 0) {
pos = 0x80 + col;
} else {
pos = 0xC0 + col;
}
lcd_command(pos);
}
void lcd_init(){
  lcd_command(0x38); //Function set -> modo de 8 bits 
  lcd_command(0x0D); // Display ON, Blinking ON
  lcd_command(0x01); //Clear Display
  HAL_Delay(2);
  lcd_command(0x06); //Entry Mode -> Modo de Incremento por 1

}