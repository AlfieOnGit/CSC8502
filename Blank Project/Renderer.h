#pragma once
#include "SkyBox.h"
#include "../NCLGL/OGLRenderer.h"
#include "nclgl/Camera.h"
#include "nclgl/SceneNode.h"
#include "../nclgl/Light.h"

class Renderer : public OGLRenderer	{
public:
	Renderer(Window &parent);
	~Renderer();
	
	void RenderScene() override;
	void UpdateScene(float dt) override;

	void FlipScene();
	
protected:
	void GenerateScreenTexture(GLuint &into, bool depth = false);
	void DrawMeshes();
	void DrawPointLights();
	void CombineBuffers();
	
	void drawNode(SceneNode *node, bool drawChildren = false);

	GLuint bufferFBO, bufferColourTex, bufferNormalTex, bufferDepthTex;
	GLuint pointLightFBO, lightDiffuseTex, lightSpecularTex;

	SceneNode *scene;
	SkyBox *skyBox;
	Camera *camera;
	Light *pointLights;
	Mesh *sphere, *quad;
};
