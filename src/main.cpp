#include <Arduino.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>
#include <Fonts/FreeSans12pt7b.h>

const uint8_t PIN_SPI_RST = 2; // Used for ILI9341
const uint8_t PIN_SPI_DC = 4; // Used for ILI9341
const uint8_t PIN_SPI_CS_SS = 15; // Used for ILI9341
const uint8_t PIN_SPI_SDA_SDI_DARA_IN_MOSI = 13; // Used for ILI9341
const uint8_t PIN_SPI_SDO_DATA_OUT_MISO = 12; // Used for ILI9341
const uint8_t PIN_SPI_SCK_CLK_SCL_SCLK = 14; // Used for ILI9341
const uint8_t PIN_I2C_SDA = 21;
const uint8_t PIN_I2C_SCL = 22;
const uint8_t PIN_UART_TX = 17;
const uint8_t PIN_UART_RX = 16;
const uint8_t PIN_DISPLAY_BRIGHTNESS = 5;

const uint16_t DISPLAY_COLOR = ILI9341_BLACK;
const uint16_t DISPLAY_TEXT_COLOR = 0x5FFF;
volatile int LCD_BRIGHTNESS = 20;

// NEED CHANGE IN Adafruit_ILI9341.h
// #define ILI9341_TFTWIDTH 320
// #define ILI9341_TFTHEIGHT 240

Adafruit_ILI9341 display = Adafruit_ILI9341(
        PIN_SPI_CS_SS,
        PIN_SPI_DC,
        PIN_SPI_RST
);

TaskHandle_t Task1;
TaskHandle_t Task2;

void setupDisplay() {
    SPI.begin(PIN_SPI_SCK_CLK_SCL_SCLK, PIN_SPI_SDO_DATA_OUT_MISO, PIN_SPI_SDA_SDI_DARA_IN_MOSI, PIN_SPI_CS_SS);
    pinMode(PIN_DISPLAY_BRIGHTNESS, OUTPUT);
//    analogWrite(PIN_DISPLAY_BRIGHTNESS, LCD_BRIGHTNESS);
    digitalWrite(PIN_DISPLAY_BRIGHTNESS, HIGH);
    display.begin(80000000);
    display.setRotation(1);
    display.setTextSize(1);
    display.setFont(&FreeSans12pt7b);
    display.setTextColor(DISPLAY_TEXT_COLOR);
    display.fillScreen(DISPLAY_COLOR);
    display.setCursor(90, 160);
    display.println("Start");
}

void task1(void *pvParameters) {
    while (true) {

    }
}

void task2(void *pvParameters) {
    while (true) {

    }
}

void setupTasks() {
    xTaskCreatePinnedToCore(
            task1,
            "task1",
            50000,
            NULL,
            1,
            &Task1,
            0);
    xTaskCreatePinnedToCore(
            task2,
            "task2",
            50000,
            NULL,
            1,
            &Task2,
            1);
}

void setup() {
    setupDisplay();
//    setupTasks();
}

void loop() {

}