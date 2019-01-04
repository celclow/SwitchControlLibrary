#include "SwitchControlLibrary.h"

#if defined(_USING_HID)

static const uint8_t _hidReportDescriptor[] PROGMEM = {
    0x05, 0x01,       //   USAGE_PAGE (Generic Desktop)
    0x09, 0x05,       //   USAGE (Game Pad)
    0xa1, 0x01,       //   COLLECTION (Application)
    0x15, 0x00,       //   LOGICAL_MINIMUM (0)
    0x25, 0x01,       //   LOGICAL_MAXIMUM (1)
    0x35, 0x00,       //   PHYSICAL_MINIMUM (0)
    0x45, 0x01,       //   PHYSICAL_MAXIMUM (1)
    0x75, 0x01,       //   REPORT_SIZE (1)
    0x95, 0x10,       //   REPORT_COUNT (16)
    0x05, 0x09,       //   USAGE_PAGE (Button)
    0x19, 0x01,       //   USAGE_MINIMUM (1)
    0x29, 0x10,       //   USAGE_MAXIMUM (16)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x05, 0x01,       //   USAGE_PAGE (Generic Desktop)
    0x25, 0x07,       //   LOGICAL_MAXIMUM (7)
    0x46, 0x3b, 0x01, //   PHYSICAL_MAXIMUM (315)
    0x75, 0x04,       //   REPORT_SIZE (4)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x65, 0x14,       //   UNIT (20)
    0x09, 0x39,       //   USAGE (Hat Switch)
    0x81, 0x42,       //   INPUT (Data,Var,Abs)
    0x65, 0x00,       //   UNIT (0)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x81, 0x01,       //   INPUT (Cnst,Arr,Abs)
    0x26, 0xff, 0x00, //   LOGICAL_MAXIMUM (255)
    0x46, 0xff, 0x00, //   PHYSICAL_MAXIMUM (255)
    0x09, 0x30,       //   USAGE (X)
    0x09, 0x31,       //   USAGE (Y)
    0x09, 0x32,       //   USAGE (Z)
    0x09, 0x35,       //   USAGE (Rz)
    0x75, 0x08,       //   REPORT_SIZE (8)
    0x95, 0x04,       //   REPORT_COUNT (4)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x06, 0x00, 0xff, //   USAGE_PAGE (Vendor Defined 65280)
    0x09, 0x20,       //   USAGE (32)
    0x95, 0x01,       //   REPORT_COUNT (1)
    0x81, 0x02,       //   INPUT (Data,Var,Abs)
    0x0a, 0x21, 0x26, //   USAGE (9761)
    0x95, 0x08,       //   REPORT_COUNT (8)
    0x91, 0x02,       //   OUTPUT (Data,Var,Abs)
    0xc0              // END_COLLECTION
};

SwitchControlLibrary_::SwitchControlLibrary_()
{
    static HIDSubDescriptor node(_hidReportDescriptor, sizeof(_hidReportDescriptor));
    CustomHID().AppendDescriptor(&node);

    memset(&_joystickInputData, 0, sizeof(USB_JoystickReport_Input_t));
    _joystickInputData.LX = (uint8_t)Stick::CENTER;
    _joystickInputData.LY = (uint16_t)Stick::CENTER;
    _joystickInputData.RX = (uint16_t)Stick::CENTER;
    _joystickInputData.RY = (uint16_t)Stick::CENTER;
    _joystickInputData.Hat = (uint16_t)Hat::CENTER;
}

void SwitchControlLibrary_::SendReport()
{
    CustomHID().SendReport(&_joystickInputData, sizeof(USB_JoystickReport_Input_t));
}

void SwitchControlLibrary_::PressButtonY()
{
    _joystickInputData.Button |= (uint16_t)Button::Y;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonY()
{
    _joystickInputData.Button &= ((uint16_t)Button::Y ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonB()
{
    _joystickInputData.Button |= (uint16_t)Button::B;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonB()
{
    _joystickInputData.Button &= ((uint16_t)Button::B ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonA()
{
    _joystickInputData.Button |= (uint16_t)Button::A;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonA()
{
    _joystickInputData.Button &= ((uint16_t)Button::A ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonX()
{
    _joystickInputData.Button |= (uint16_t)Button::X;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonX()
{
    _joystickInputData.Button &= ((uint16_t)Button::X ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonL()
{
    _joystickInputData.Button |= (uint16_t)Button::L;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonL()
{
    _joystickInputData.Button &= ((uint16_t)Button::L ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonR()
{
    _joystickInputData.Button |= (uint16_t)Button::R;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonR()
{
    _joystickInputData.Button &= ((uint16_t)Button::R ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonZL()
{
    _joystickInputData.Button |= (uint16_t)Button::ZL;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonZL()
{
    _joystickInputData.Button &= ((uint16_t)Button::ZL ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonZR()
{
    _joystickInputData.Button |= (uint16_t)Button::ZR;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonZR()
{
    _joystickInputData.Button &= ((uint16_t)Button::ZR ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonMinus()
{
    _joystickInputData.Button |= (uint16_t)Button::MINUS;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonMinus()
{
    _joystickInputData.Button &= ((uint16_t)Button::MINUS ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonPlus()
{
    _joystickInputData.Button |= (uint16_t)Button::PLUS;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonPlus()
{
    _joystickInputData.Button &= ((uint16_t)Button::PLUS ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonLClick()
{
    _joystickInputData.Button |= (uint16_t)Button::LCLICK;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonLClick()
{
    _joystickInputData.Button &= ((uint16_t)Button::LCLICK ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonRClick()
{
    _joystickInputData.Button |= (uint16_t)Button::RCLICK;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonRClick()
{
    _joystickInputData.Button &= ((uint16_t)Button::RCLICK ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonHome()
{
    _joystickInputData.Button |= (uint16_t)Button::HOME;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonHome()
{
    _joystickInputData.Button &= ((uint16_t)Button::HOME ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::PressButtonCapture()
{
    _joystickInputData.Button |= (uint16_t)Button::CAPTURE;
    SendReport();
}

void SwitchControlLibrary_::ReleaseButtonCapture()
{
    _joystickInputData.Button &= ((uint16_t)Button::CAPTURE ^ 0xffff);
    SendReport();
}

void SwitchControlLibrary_::MoveHat(uint8_t hat)
{
    _joystickInputData.Hat = hat;
    SendReport();
}

void SwitchControlLibrary_::MoveLeftStick(uint8_t lx, uint8_t ly)
{
    _joystickInputData.LX = lx;
    _joystickInputData.LY = ly;
    SendReport();
}

void SwitchControlLibrary_::MoveRightStick(uint8_t rx, uint8_t ry)
{
    _joystickInputData.RX = rx;
    _joystickInputData.RY = ry;
    SendReport();
}

SwitchControlLibrary_ &SwitchControlLibrary()
{
    static SwitchControlLibrary_ obj;
    return obj;
}

#endif
