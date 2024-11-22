#pragma once
#include "Matrix4.h"
#include "Vector3.h"

class Camera
{
public:
    Camera()
    {
        yaw = 0.0f;
        pitch = 0.0f;
    }

    Camera(float pitch, float yaw, Vector3 position)
    {
        this->pitch = pitch;
        this->yaw = yaw;
        this->position, this->startPos = position;
        std::cout << "Y = " << startPos.y << "!\n";
    }

    ~Camera() {}

    void UpdateCamera(float dt = 1.0f);

    Matrix4 BuildViewMatrix();

    Vector3 GetPosition() const { return position; }
    void SetPosition(Vector3 val) { this->position = val; }

    float GetYaw() const { return yaw; }
    void SetYaw(float y) { this->yaw = y; }

    float GetPitch() const { return pitch; }
    void SetPitch(float p) { this->pitch = p; }

    bool IsFree() const { return isFree; }
    void SetIsFree(bool isFree) { this->isFree = isFree; }

protected:
    bool isFree = false;
    float count = 0.0f;
    float yaw;
    float pitch;
    Vector3 position, startPos;
};