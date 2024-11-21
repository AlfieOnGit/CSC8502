#pragma once
#include "../NCLGL/OGLRenderer.h"
#include "../nclgl/Mesh.h"
#include "nclgl/Camera.h"
#include "nclgl/HeightMap.h"
#include "nclgl/SceneNode.h"

class Renderer : public OGLRenderer	{
public:
	Renderer(Window &parent);
	 ~Renderer();
	 void RenderScene()				override;
	 void UpdateScene(float dt)	    override;
protected:
	void drawSkyBox();
	void drawTerrain();
	void drawScene();
	void drawNode(SceneNode *node);
	
	Shader *sceneShader, *skyBoxShader, *bumpShader;
	SceneNode *scene;
	Camera *camera;
	GLuint terrainTex, skyBoxTex;
	Mesh *quad; // TODO: To be replaced with sceneNode ideally? Point is we needed SOMETHING to call Draw on
};

#define SKYBOXTEXDIR "Assets/SkyBox/Texture/"
