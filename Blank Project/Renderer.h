#pragma once
#include "Moon.h"
#include "../NCLGL/OGLRenderer.h"
#include "../nclgl/Mesh.h"
#include "nclgl/Camera.h"
#include "nclgl/HeightMap.h"
#include "nclgl/SceneNode.h"

class Renderer : public OGLRenderer	{
public:
	Renderer(Window &parent);
	 ~Renderer(void);
	 void RenderScene()				override;
	 void UpdateScene(float dt)	    override;
protected:
	void drawSkyBox();
	void drawTerrain();
	void drawNode(SceneNode *node);
	
	Shader *basicShader, *skyBoxShader;
	//HeightMap *terrain;
	Camera *camera;
	GLuint terrainTex, skyBoxTex;
	Mesh *quad; // TODO: To be replaced with sceneNode ideally? Point is we needed SOMETHING to call Draw on
	Moon *moon;
};

#define SKYBOXTEXDIR "Assets/SkyBox/Texture/"
