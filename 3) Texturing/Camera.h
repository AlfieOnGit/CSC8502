#pragma once
#include "nclgl/Matrix4.h"
#include "nclgl/Vector3.h"

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
        this->position = position;
    }

    ~Camera() {};

    void UpdateCamera(float dt = 1.0f);

    Matrix4 BuildViewMatrix();

    Vector3 GetPosition() const;
    void SetPosition(Vector3 val) { this->position = val; }

    float GetYaw() const { return yaw; }
    void SetYaw(float y) { this->yaw = y; }

    float GetPitch() const { return GetPitch(); }
    void SetPitch(float p) { this->pitch = p; }

protected:
    float yaw;
    float pitch;
    Vector3 position;
};
