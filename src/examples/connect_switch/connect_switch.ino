#include <SwitchControlLibrary.h>

void setup()
{
    SwitchControlLibrary();
}

int loopCount = 0;
void loop()
{
    if (100 < loopCount)
        loopCount = 0;

    if (loopCount == 50)
    {
        SwitchControlLibrary().pressButton(Button::L);
        SwitchControlLibrary().pressButton(Button::R);
        SwitchControlLibrary().sendReport();

        SwitchControlLibrary().releaseButton(Button::L);
        SwitchControlLibrary().releaseButton(Button::R);
        SwitchControlLibrary().sendReport();
    }

    if (loopCount == 100)
    {
        SwitchControlLibrary().pressButton(Button::A);
        SwitchControlLibrary().releaseButton(Button::A);
    }

    SwitchControlLibrary().sendReport();

    loopCount++;
}
