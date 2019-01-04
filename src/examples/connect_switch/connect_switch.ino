#include <SwitchControlLibrary.h>

void setup()
{
}

int loopCount = 0;
void loop()
{
	if (100 < loopCount)
		loopCount = 0;

	if (loopCount == 50)
	{
		SwitchControlLibrary().PressButtonL();
		SwitchControlLibrary().PressButtonR();
		SwitchControlLibrary().ReleaseButtonL();
		SwitchControlLibrary().ReleaseButtonR();
	}

	if (loopCount == 100)
	{
		SwitchControlLibrary().PressButtonA();
		SwitchControlLibrary().ReleaseButtonA();
	}

	loopCount++;
}
