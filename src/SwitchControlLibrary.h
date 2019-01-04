#include <ArduinoSTL.h>
#include <list>

#include "CustomHID.h"

enum class Button : uint16_t
{
	Y = 0x0001,
	B = 0x0002,
	A = 0x0004,
	X = 0x0008,
	L = 0x0010,
	R = 0x0020,
	ZL = 0x0040,
	ZR = 0x0080,
	MINUS = 0x0100,
	PLUS = 0x0200,
	LCLICK = 0x0400,
	RCLICK = 0x0800,
	HOME = 0x1000,
	CAPTURE = 0x2000
};

enum class Hat : uint8_t
{
	TOP = 0x00,
	TOP_RIGHT = 0x01,
	RIGHT = 0x02,
	BOTTOM_RIGHT = 0x03,
	BOTTOM = 0x04,
	BOTTOM_LEFT = 0x05,
	LEFT = 0x06,
	TOP_LEFT = 0x07,
	CENTER = 0x08
};

enum class Stick : uint8_t
{
	MIN = 0,
	CENTER = 128,
	MAX = 255
};

typedef struct
{
	uint16_t Button;
	uint8_t Hat;
	uint8_t LX;
	uint8_t LY;
	uint8_t RX;
	uint8_t RY;
	uint8_t VendorSpec;
} USB_JoystickReport_Input_t;

class SwitchControlLibrary_
{
  private:
	USB_JoystickReport_Input_t _joystickInputData;
	void SendReport();

  public:
	SwitchControlLibrary_();

	void PressButtonY();
	void ReleaseButtonY();
	void PressButtonB();
	void ReleaseButtonB();
	void PressButtonA();
	void ReleaseButtonA();
	void PressButtonX();
	void ReleaseButtonX();
	void PressButtonL();
	void ReleaseButtonL();
	void PressButtonR();
	void ReleaseButtonR();
	void PressButtonZL();
	void ReleaseButtonZL();
	void PressButtonZR();
	void ReleaseButtonZR();
	void PressButtonMinus();
	void ReleaseButtonMinus();
	void PressButtonPlus();
	void ReleaseButtonPlus();
	void PressButtonLClick();
	void ReleaseButtonLClick();
	void PressButtonRClick();
	void ReleaseButtonRClick();
	void PressButtonHome();
	void ReleaseButtonHome();
	void PressButtonCapture();
	void ReleaseButtonCapture();
	void MoveHat(uint8_t hat);
	void MoveLeftStick(uint8_t lx, uint8_t ly);
	void MoveRightStick(uint8_t rx, uint8_t ry);
};

SwitchControlLibrary_ &SwitchControlLibrary();
