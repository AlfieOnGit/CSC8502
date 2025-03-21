﻿#include "SceneNode.h"

SceneNode::SceneNode(Mesh* mesh, Vector4 colour)
{
    this->mesh = mesh;
    this->colour = colour;
    boundingRadius = 1.0f;
    distanceFromCamera = 0.0f;
    texture = 0;
    parent = NULL;
    modelScale = Vector3(1, 1, 1);
}

SceneNode::~SceneNode()
{
    for (unsigned int i = 0; i < children.size(); i++) delete children[i];
}

void SceneNode::AddChild(SceneNode* s)
{
    children.push_back(s);
    s->parent = this;
}

void SceneNode::Draw(OGLRenderer &r)
{
    if (mesh) mesh->Draw();
}

void SceneNode::Update(float dt)
{
    if (parent) worldTransform = parent->worldTransform * transform;
    else worldTransform = transform;

    for (vector<SceneNode*>::iterator i = children.begin(); i != children.end(); i++) (*i)->Update(dt);
}

void SceneNode::Flip()
{
    for (vector<SceneNode*>::iterator i = children.begin(); i != children.end(); i++) (*i)->Flip();
}

