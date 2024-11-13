#pragma once
#include "nclgl/OGLRenderer.h"
#include "nclgl/Camera.h"
#include "nclgl/Frustum.h"
#include "nclgl/SceneNode.h"

class Renderer : public OGLRenderer
{
public:
    Renderer(Window &parent);
    ~Renderer();

    void UpdateScene(float dt) override;
    void RenderScene() override;

protected:
    void BuildNodeLists(SceneNode *from);
    void SortNodeLists();
    void ClearNodeLists();
    void DrawNodes();
    void DrawNode(SceneNode *n);

    SceneNode* root;
    Camera* camera;
    Mesh* quad;
    Mesh* cube;
    Shader* shader;
    GLuint texture;

    Frustum frameFrustum;

    vector<SceneNode*> transparentNodelist;
    vector<SceneNode*> nodeList;
};
