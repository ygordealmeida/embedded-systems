#include "keypad.h"

char read_keypad(void)
{
char keys[4][4] = {
{'1', '2', '3', 'A'},
{'4', '5', '6', 'B'},
{'7', '8', '9', 'C'},
{'*', '0', '#', 'D'}};
for (int row = 0; row < 4; row++)
{
/* Set all rows to high */
HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0|GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_SET);
/* Set the current row to low */
HAL_GPIO_WritePin(GPIOB, (GPIO_PIN_0 << row), GPIO_PIN_RESET);
for (int col = 0; col < 4; col++)
{
if (HAL_GPIO_ReadPin(GPIOB, (GPIO_PIN_4 << col)) == GPIO_PIN_RESET)
{
while (HAL_GPIO_ReadPin(GPIOB, (GPIO_PIN_4 << col)) == GPIO_PIN_RESET); // Wait for key release
return keys[row][col];
}
}
}
return 0; // No key pressed
}