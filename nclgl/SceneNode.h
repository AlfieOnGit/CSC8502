#pragma once
#include "Mesh.h"

class SceneNode
{
public:
    SceneNode(Mesh* m = NULL, Vector4 colour = Vector4(1, 1, 1, 1));
    ~SceneNode();

    void SetTransform(const Matrix4 &matrix) { transform = matrix; }
    const Matrix4& GetTransform() const { return transform; }
    Matrix4 GetWorldTransform() const { return worldTransform; }

    Vector4 GetColour() const { return colour; }
    void SetColour(Vector4 c) { colour = c; }

    Vector3 GetModelScale() const { return modelScale; }
    void SetModelScale(Vector3 s) { modelScale = s; }

    Mesh* GetMesh() const { return mesh; }
    void SetMesh(Mesh* m) { mesh = m; }

    float GetBoundingRadius() const { return boundingRadius; }
    void SetBoundingRadius(float f) { boundingRadius = f; }

    float GetCameraDistance() const { return distanceFromCamera; }
    void SetCameraDistance(float f) { distanceFromCamera = f; }

    void SetTexture(GLuint tex) { texture = tex; }
    GLuint GetTexture() const { return texture; }

    void SetShader(Shader *shader) { this->shader = shader; }
    Shader *GetShader() const { return shader; }

    static bool CompareByCameraDistance(SceneNode *a, SceneNode *b)
    {
        return a->distanceFromCamera < b->distanceFromCamera;
    }

    void AddChild(SceneNode* s);

    virtual void Update(float dt);
    virtual void Draw(OGLRenderer &r);

    virtual void Flip();

    std::vector<SceneNode*>::const_iterator GetChildIteratorStart() { return children.begin(); }
    std::vector<SceneNode*>::const_iterator GetChildIteratorEnd() { return children.end(); }

protected:
    SceneNode* parent;
    Mesh* mesh;
    Matrix4 worldTransform;
    Matrix4 transform;
    Vector3 modelScale;
    Vector4 colour;
    float distanceFromCamera;
    float boundingRadius;
    GLuint texture;
    Shader *shader;
    std::vector<SceneNode*> children;
};
