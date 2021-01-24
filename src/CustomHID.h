#pragma once

#include <HID.h>

#if defined(USBCON)

class CustomHID_ : public HID_
{
public:
    CustomHID_();
    int SendReport(const void *data, int len);
};

CustomHID_ &CustomHID();

#endif /* if defined(USBCON) */
