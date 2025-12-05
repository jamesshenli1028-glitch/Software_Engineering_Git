#pragma once

class DeviceInterface
{
public:
    virtual ~DeviceInterface() = default;

    virtual void startDevice() = 0;
    virtual void stopDevice() = 0;
};