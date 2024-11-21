#pragma once
#include "SkyBox.h"
#include "../NCLGL/OGLRenderer.h"
#include "nclgl/Camera.h"
#include "nclgl/SceneNode.h"

class Renderer : public OGLRenderer	{
public:
	Renderer(Window &parent);
	 ~Renderer();
	 void RenderScene()				override;
	 void UpdateScene(float dt)	    override;
protected:
	void drawNode(SceneNode *node, bool drawChildren = false);
	
	Shader *sceneShader, *skyBoxShader, *bumpShader;
	SceneNode *scene;
	SkyBox *skyBox;
	Camera *camera;
};
