#include "Renderer.h"

#include "Moon.h"

Renderer::Renderer(Window &parent) : OGLRenderer(parent)	{

	quad = Mesh::GenerateQuad(); // TODO: Remove probably

	// Shader setup
	//basicShader = new Shader("TexturedVertex.glsl","TexturedFragment.glsl"); // TODO: Review all
	basicShader = new Shader("SceneVertex.glsl", "SceneFragment.glsl"); // TODO: Review all
	skyBoxShader = new Shader("skyboxVertex.glsl", "skyboxFragment.glsl");
	if(!basicShader->LoadSuccess() || !skyBoxShader->LoadSuccess()) return;

	// Moon setup
	moon = new Moon(1000);
	terrainTex = SOIL_load_OGL_texture(TEXTUREDIR"Barren Reds.JPG", SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID, SOIL_FLAG_MIPMAPS); // TODO: Make custom
	moon->SetTexture(terrainTex);

	// Terrain setup
	//terrain = new HeightMap(TEXTUREDIR"noise.png"); // TODO: Make custom

	// Skybox setup
	skyBoxTex = SOIL_load_OGL_cubemap(
		SKYBOXTEXDIR"Left.png", SKYBOXTEXDIR"Right.png", SKYBOXTEXDIR"Up.png",
		SKYBOXTEXDIR"Down.png", SKYBOXTEXDIR"Front.png", SKYBOXTEXDIR"Back.png",
		SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, 0);

	// Textures check
	if (!terrainTex | !skyBoxTex) return;
	SetTextureRepeating(terrainTex, true);

	// Camera setup
	//camera = new Camera(0, 0, Vector3(0, 0, 0));
	//camera = new Camera(0, 0, terrain->GetHeightMapSize() * Vector3(0.5, 2, 0.5));
	camera = new Camera(0, 0, Vector3(0, moon->GetRadius() * 1.5f, 0));

	projMatrix = Matrix4::Perspective(1.0f, 10000.0f, (float)width / (float)height, 45.0f);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_TEXTURE_CUBE_MAP_SEAMLESS);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	init = true;
}

Renderer::~Renderer()	{
	delete basicShader;
	//delete terrain;
	delete camera;
	delete quad;
	glDeleteTextures(1, &terrainTex);
}

void Renderer::UpdateScene(float dt) {
	camera->UpdateCamera(dt);
	viewMatrix = camera->BuildViewMatrix();

	Vector3 pos = camera->GetPosition();
}

void Renderer::RenderScene()	{
	glClearColor(0.2f,0.2f,0.2f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawSkyBox();
	//drawTerrain();
	//drawScene();
	
	BindShader(basicShader);
	UpdateShaderMatrices();
	drawNode(moon);
}

void Renderer::drawSkyBox()
{
	glDepthMask(GL_FALSE);

	BindShader(skyBoxShader);
	UpdateShaderMatrices();
	glUniform1i(glGetUniformLocation(skyBoxShader->GetProgram(), "cubeTex"), 0);
	glBindTexture(GL_TEXTURE_CUBE_MAP, skyBoxTex);

	quad->Draw();

	glDepthMask(GL_TRUE);
}

// void Renderer::drawTerrain() // TODO: Remove
// {
// 	BindShader(basicShader);
// 	UpdateShaderMatrices();
// 	glUniform1i(glGetUniformLocation(basicShader->GetProgram(), "diffuseTex"), 0);
// 	glBindTexture(GL_TEXTURE_2D, terrainTex);
// 	terrain->Draw();
// }

//void Renderer::drawScene()
//{
//	BindShader(basicShader);
//	UpdateShaderMatrices();
//	moon->Draw(*this);
//}

void Renderer::drawNode(SceneNode* node)
{
	if (node->GetMesh())
	{
		Matrix4 model = node->GetWorldTransform() * Matrix4::Scale(node->GetModelScale());
		glUniformMatrix4fv(glGetUniformLocation(basicShader->GetProgram(), "modelMatrix"),
			1, false, model.values);

		glUniform4fv(glGetUniformLocation(basicShader->GetProgram(), "nodeColour"),
			1, (float*)&node->GetColour());

		GLuint texture = node->GetTexture();
		glBindTexture(GL_TEXTURE_2D, texture);
		glUniform1i(glGetUniformLocation(basicShader->GetProgram(), "useTexture"), texture);

		node->Draw(*this);
	}

	for (vector<SceneNode*>::const_iterator i = node->GetChildIteratorStart(); i != node->GetChildIteratorEnd(); ++i)
		drawNode(*i);
}


