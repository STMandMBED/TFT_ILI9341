#include "mbed.h"

// Библиотека для работы с дисплеем ILI9341
#include "ILI9341.h"

// Библиотека шрифта
#include "Arial24x23.h"

// Создаем объект tft класса ILI9341 (тип дисплея)
ILI9341 tft(SPI_8, 10000000, PB_5, PB_4, PB_3, PA_15, PA_12, PA_11, "tft");

// Переменные для циклической смены цветности и ориентации текста
int FOREGROUND_COLORS[] = {White, Cyan, Red, Magenta, Yellow, Orange, GreenYellow};
int BACKGROUND_COLORS[] = {Black, Navy, DarkGreen, DarkCyan, Maroon, White, Yellow};
int color = 0;

int orient = 0;

int main()
{
    // Устанавливаем шрифт
    tft.set_font((unsigned char *)Arial24x23);

    while (1)
    {
        // Очищаем экран
        tft.cls();

        // Устанавливаем цвет шрифта
        tft.foreground(FOREGROUND_COLORS[color]);

        // Устанавливаем цвет фона
        tft.background(BACKGROUND_COLORS[color]);

        // Позиция курсора
        tft.locate(0, 200);

        // Ориентация текста
        tft.set_orientation(orient);

        // Выводим текст
        tft.puts("HELLO WORLD!");
        
        // изменим переменные цвета и ориентации текста
        color++;
        orient++;
        if (color > 6)
            color = 0;
        if (orient > 3)
            orient = 0;
            
        // ждем 200 мс
        wait_ms(200);
    }
}
