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
void LedControlModule::showTime(const SimpleTime &simpleTime, const RgbwColor &ledColor)
{
    pixelStrip->ClearTo(RgbwColor(0));
    /* for (int i = 0; i < 110; i++)
    {
        pixelStrip->SetPixelColor(i, RgbwColor(240, 250, 100, 255));
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
void LedControlModule::showConfigWifi(const RgbwColor &ledColor)
{
    pixelStrip->ClearTo(RgbwColor(0));
    enableLedWord(&WORD_FUNK, ledColor);
    pixelStrip->Show();
}

/**
 * Enable time words.
 * @param simpleTime Time to be shown.
 * @param ledColor Optional, set LED color.
 */
void LedControlModule::enableLedWords(const SimpleTime &simpleTime, const RgbwColor &ledColor)
{
    enableLedWord(&PREFIX_IT, ledColor);
    enableLedWord(&PREFIX_IS, ledColor);
    int fiveMinutes = simpleTime.getMinute() / 5;

    switch (fiveMinutes)
    {
    case 0:
        enableLedWord(&SUFFIX_OCLOCK, ledColor);
        break;
    case 1:
        enableLedWord(&MINUTE_FIVE, ledColor);
        enableLedWord(&INFIX_AFTER, ledColor);
        break;
    case 2:
        enableLedWord(&MINUTE_TEN, ledColor);
        enableLedWord(&INFIX_AFTER, ledColor);
        break;
    case 3:
        enableLedWord(&MINUTE_QUARTER, ledColor);
        enableLedWord(&INFIX_AFTER, ledColor);
        break;
    case 4:
        enableLedWord(&MINUTE_TWENTY, ledColor);
        enableLedWord(&INFIX_AFTER, ledColor);
        break;
    case 5:
        enableLedWord(&MINUTE_FIVE, ledColor);
        enableLedWord(&INFIX_BEFORE, ledColor);
        enableLedWord(&MINUTE_HALF, ledColor);
        break;
    case 6:
        enableLedWord(&MINUTE_HALF, ledColor);
        break;
    case 7:
        enableLedWord(&MINUTE_FIVE, ledColor);
        enableLedWord(&INFIX_AFTER, ledColor);
        enableLedWord(&MINUTE_HALF, ledColor);
        break;
    case 8:
        enableLedWord(&MINUTE_TWENTY, ledColor);
        enableLedWord(&INFIX_BEFORE, ledColor);
        break;
    case 9:
        enableLedWord(&MINUTE_QUARTER, ledColor);
        enableLedWord(&INFIX_BEFORE, ledColor);
        break;
    case 10:
        enableLedWord(&MINUTE_TEN, ledColor);
        enableLedWord(&INFIX_BEFORE, ledColor);
        break;
    case 11:
        enableLedWord(&MINUTE_FIVE, ledColor);
        enableLedWord(&INFIX_BEFORE, ledColor);
        break;
    }

    if (fiveMinutes < 5)
    {
        int hourIndex = (simpleTime.getHour() + 11) % 12;
        enableLedWord(&HOURS[hourIndex], ledColor);
    }
    else
    {
        int hourIndex = (simpleTime.getHour()) % 12;
        enableLedWord(&HOURS[hourIndex], ledColor);
    }
};

/**
 * Enable single LedWord on LED Matrix.
 * @param ledWord
 * @param ledColor
 */
void LedControlModule::enableLedWord(const LedWord *ledWord, const RgbwColor &ledColor)
{
    // Print ledWord x and y coordinates
    Serial.print(" x: ");
    Serial.print(ledWord->getFirstPixelX());
    Serial.print(" y: ");
    Serial.print(ledWord->getFirstPixelY());
    Serial.print(" len: ");
    Serial.print(ledWord->getLength());
    Serial.println();
    for (int j = 0; j < ledWord->getLength(); j++)
    {
        Serial.print(" topo: ");
        Serial.print(topo.Map(ledWord->getFirstPixelX() + j, ledWord->getFirstPixelY()));
        Serial.println();
        pixelStrip->SetPixelColor(topo.Map(ledWord->getFirstPixelX() + j, ledWord->getFirstPixelY()), ledColor);
    }
}

/**
 * Enable minute dots in edges.
 * @param subMinute Starts from 1.
 * @param ledColor
 */
void LedControlModule::enableMinuteDots(int subMinute, const RgbwColor &ledColor)
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
    pixelStrip->ClearTo(RgbwColor(0));
    pixelStrip->Show();
};
