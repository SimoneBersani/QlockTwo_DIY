//
//  LedControlModule.cpp
//  esp8266
//
//  Created by <author> on 10/02/2018.
//
//

#include "LedControlModule.h"

LedControlModule::LedControlModule(NeoTopology<MyPanelLayout> _topo) : topo(_topo) {}
LedControlModule::~LedControlModule() {}

/**
 * Setup LEDs in NeoPixel library.
 * @param _pixelStrip NeoPixelBusType object
 */
void LedControlModule::setup(NeoPixelBusType *_pixelStrip)
{
    pixelStrip = _pixelStrip;
    pixelStrip->Begin();
    pixelStrip->Show();
};

/**
 * Show Time with LEDs.
 * @param simpleTime Time to be shown.
 * @param ledColor Optional, set LED color.
 */
void LedControlModule::showTime(const SimpleTime &simpleTime, const RgbColor &ledColor)
{
    pixelStrip->ClearTo(RgbColor(0));
    /* for (int i = 0; i < 110; i++)
    {
        pixelStrip->SetPixelColor(i, RgbColor(240, 250, 100, 255));
    } */
    enableLedWords(simpleTime, ledColor);

    /* int minuteDots = simpleTime.getMinute() % 5;
    enableMinuteDots(minuteDots, ledColor); */
    pixelStrip->Show();
};

/**
 * Show that clock is in Wifi configuration mode, in german show Word "Funk".
 * @param ledColor Optional, set LED color.
 */
void LedControlModule::showConfigWifi(const RgbColor &ledColor)
{
    pixelStrip->ClearTo(RgbColor(0));
    int width = 11;
    int height = 10;
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            if (i == 0 || j == 0 || i == width - 1 || j == height - 1)
            {
                pixelStrip->SetPixelColor(topo.Map(i, j), ledColor);
            }
        }
    }
    pixelStrip->Show();
}

/**
 * Enable time words.
 * @param simpleTime Time to be shown.
 * @param ledColor Optional, set LED color.
 */
void LedControlModule::enableLedWords(const SimpleTime &simpleTime, const RgbColor &ledColor)
{
    int fiveMinutes = simpleTime.getMinute() / 5;
    int hourIndex;

    if (fiveMinutes < 5)
    {
        hourIndex = (simpleTime.getHour() + 11) % 12;
        enableLedWord(&HOURS[hourIndex], ledColor);
    }
    else
    {
        hourIndex = (simpleTime.getHour()) % 12;
        enableLedWord(&HOURS[hourIndex], ledColor);
    }

    if (hourIndex == 0)
    {
        enableLedWord(&PREFIX_E, ledColor);
        enableLedWord(&PREFIX_L, ledColor);
    }
    else
    {
        enableLedWord(&PREFIX_SONO, ledColor);
        enableLedWord(&PREFIX_LE, ledColor);
    }

    switch (fiveMinutes)
    {
    case 0:
        break;
    case 1:
        enableLedWord(&MINUTE_FIVE, ledColor);
        enableLedWord(&AFTER_E, ledColor);
        break;
    case 2:
        enableLedWord(&MINUTE_TEN, ledColor);
        enableLedWord(&AFTER_E, ledColor);
        break;
    case 3:
        enableLedWord(&MINUTE_QUARTER_INFIX, ledColor);
        enableLedWord(&MINUTE_QUARTER_SUFFIX, ledColor);
        enableLedWord(&AFTER_E, ledColor);
        break;
    case 4:
        enableLedWord(&MINUTE_TWENTY, ledColor);
        enableLedWord(&AFTER_E, ledColor);
        break;
    case 5:
        enableLedWord(&MINUTE_TWENTY, ledColor);
        enableLedWord(&MINUTE_FIVE, ledColor);
        enableLedWord(&AFTER_E, ledColor);
        break;
    case 6:
        enableLedWord(&MINUTE_HALF, ledColor);
        enableLedWord(&AFTER_E, ledColor);
        break;
    case 7:
        enableLedWord(&BEFORE_MENO, ledColor);
        enableLedWord(&MINUTE_TWENTY, ledColor);
        enableLedWord(&MINUTE_FIVE, ledColor);
        break;
    case 8:
        enableLedWord(&MINUTE_TWENTY, ledColor);
        enableLedWord(&BEFORE_MENO, ledColor);
        break;
    case 9:
        enableLedWord(&MINUTE_QUARTER_INFIX, ledColor);
        enableLedWord(&MINUTE_QUARTER_SUFFIX, ledColor);
        enableLedWord(&BEFORE_MENO, ledColor);
        break;
    case 10:
        enableLedWord(&MINUTE_TEN, ledColor);
        enableLedWord(&BEFORE_MENO, ledColor);
        break;
    case 11:
        enableLedWord(&MINUTE_FIVE, ledColor);
        enableLedWord(&BEFORE_MENO, ledColor);
        break;
    }
};

/**
 * Enable single LedWord on LED Matrix.
 * @param ledWord
 * @param ledColor
 */
void LedControlModule::enableLedWord(const LedWord *ledWord, const RgbColor &ledColor)
{
    // Print ledWord x and y coordinates
    /* Serial.print(" x: ");
    Serial.print(ledWord->getFirstPixelX());
    Serial.print(" y: ");
    Serial.print(ledWord->getFirstPixelY());
    Serial.print(" len: ");
    Serial.print(ledWord->getLength());
    Serial.println(); */
    for (int j = 0; j < ledWord->getLength(); j++)
    {
        /* Serial.print(" topo: ");
        Serial.print(topo.Map(ledWord->getFirstPixelX() + j, ledWord->getFirstPixelY()));
        Serial.println(); */
        pixelStrip->SetPixelColor(topo.Map(ledWord->getFirstPixelX() + j, ledWord->getFirstPixelY()), ledColor);
    }
}

/**
 * Enable minute dots in edges.
 * @param subMinute Starts from 1.
 * @param ledColor
 */
void LedControlModule::enableMinuteDots(int subMinute, const RgbColor &ledColor)
{
    for (int i = 1; i <= subMinute; i++)
    {
        int j = 110 + ((i + 2) % 4);
        pixelStrip->SetPixelColor(j, ledColor);
    }
}

/**
 * Show on all LEDs black.
 */
void LedControlModule::disableLeds()
{
    pixelStrip->ClearTo(RgbColor(0));
    pixelStrip->Show();
};
