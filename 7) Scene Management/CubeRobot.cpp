﻿#include "CubeRobot.h"

CubeRobot::CubeRobot(Mesh* cube)
{
    SceneNode* body = new SceneNode(cube, Vector4(1, 0, 0, 1)); // RED
    body->SetModelScale(Vector3(10, 15, 5));
    body->SetTransform(Matrix4::Translation(Vector3(0, 35, 0)));
    body->SetBoundingRadius(15.0f);
    AddChild(body);

    head = new SceneNode(cube, Vector4(0, 1, 0, 1)); // GREEN
    head->SetModelScale(Vector3(5, 5, 5));
    head->SetTransform(Matrix4::Translation(Vector3(0, 30, 0)));
    head->SetBoundingRadius(5.0f);
    body->AddChild(head);

    leftArm = new SceneNode(cube, Vector4(0, 0, 1, 1)); // BLUE
    leftArm->SetModelScale(Vector3(3, -18, 3));
    leftArm->SetTransform(Matrix4::Translation(Vector3(-12, 30, -1)));
    leftArm->SetBoundingRadius(18.0f);
    body->AddChild(leftArm);

    rightArm = new SceneNode(cube, Vector4(0, 0, 1, 1)); // BLUE
    rightArm->SetModelScale(Vector3(3, -18, 3));
    rightArm->SetTransform(Matrix4::Translation(Vector3(12, 30, -1)));
    rightArm->SetBoundingRadius(18.0f);
    body->AddChild(rightArm);

    SceneNode* leftLeg = new SceneNode(cube, Vector4(0, 0, 1, 1)); // BLUE
    leftLeg->SetModelScale(Vector3(3, -17.5, 3));
    leftLeg->SetTransform(Matrix4::Translation(Vector3(-8, 0, 0)));
    leftLeg->SetBoundingRadius(18.0f);
    body->AddChild(leftLeg);

    SceneNode* rightLeg = new SceneNode(cube, Vector4(0, 0, 1, 1)); // BLUE
    rightLeg->SetModelScale(Vector3(3, -17.5, 3));
    rightLeg->SetTransform(Matrix4::Translation(Vector3(8, 0, 0)));
    rightLeg->SetBoundingRadius(18.0f);
    body->AddChild(rightLeg);
}

void CubeRobot::Update(float dt)
{
    transform = transform * Matrix4::Rotation(30.0f * dt, Vector3(0, 1, 0));

    head->SetTransform(head->GetTransform()
        * Matrix4::Rotation(-30.0f * dt, Vector3(0, 1, 0)));
    leftArm->SetTransform(leftArm->GetTransform()
        * Matrix4::Rotation(-30.0f * dt, Vector3(1, 0, 0)));
    rightArm->SetTransform(rightArm->GetTransform()
        * Matrix4::Rotation(-30.0f * dt, Vector3(1, 0, 0)));

    SceneNode::Update(dt);
}

