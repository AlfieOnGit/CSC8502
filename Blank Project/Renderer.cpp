#include "Renderer.h"

#include "Terrain.h"

Renderer::Renderer(Window &parent) : OGLRenderer(parent)	{

	std::cout << "Test";

	quad = Mesh::GenerateQuad(); // TODO: Remove probably

	// Shader setup
	sceneShader = new Shader("SceneVertex.glsl", "SceneFragment.glsl"); // TODO: Review all
	skyBoxShader = new Shader("skyboxVertex.glsl", "skyboxFragment.glsl");
	bumpShader = new Shader("BumpVertex.glsl", "BumpFragment.glsl");
	if(!sceneShader->LoadSuccess() || !skyBoxShader->LoadSuccess() || !bumpShader->LoadSuccess()) return;

	// Terrain setup
	auto *terrain = new Terrain();
	terrain->SetShader(bumpShader);
	scene = terrain;

	// Skybox setup
	skyBoxTex = SOIL_load_OGL_cubemap(
		SKYBOXTEXDIR"Left.png", SKYBOXTEXDIR"Right.png", SKYBOXTEXDIR"Up.png",
		SKYBOXTEXDIR"Down.png", SKYBOXTEXDIR"Front.png", SKYBOXTEXDIR"Back.png",
		SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, 0);

	// Textures check
	if (!scene->GetTexture() | !skyBoxTex) return;
	SetTextureRepeating(scene->GetTexture(), true);

	// Camera setup
	camera = new Camera(0, 0, static_cast<Terrain*>(scene)->GetHeightMapSize() * Vector3(0.5, 2, 0.5));
	terrain->SetCamera(camera);

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
	delete sceneShader;
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
	drawScene();
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

void Renderer::drawScene()
{
	BindShader(sceneShader);
	UpdateShaderMatrices();
	drawNode(scene);
}

void Renderer::drawNode(SceneNode* node)
{
	if (node->GetMesh()) node->Draw(*this);

	for (vector<SceneNode*>::const_iterator i = node->GetChildIteratorStart(); i != node->GetChildIteratorEnd(); ++i)
		drawNode(*i);
}


