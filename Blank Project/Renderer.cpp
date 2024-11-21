#include "Renderer.h"

#include "Terrain.h"

Renderer::Renderer(Window &parent) : OGLRenderer(parent)	{

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
	skyBox = new SkyBox();
	skyBox->SetShader(skyBoxShader);

	// Textures check
	if (!scene->GetTexture()) return;
	SetTextureRepeating(scene->GetTexture(), true);

	// Camera setup
	camera = new Camera(0, 0, terrain->GetHeightMapSize() * Vector3(0.5, 2, 0.5));
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
	delete skyBoxShader;
	delete bumpShader;
	delete scene;
	delete skyBox;
	delete camera;
}

void Renderer::UpdateScene(float dt) {
	camera->UpdateCamera(dt);
	viewMatrix = camera->BuildViewMatrix();

	Vector3 pos = camera->GetPosition();
}

void Renderer::RenderScene()	{
	glClearColor(0.2f,0.2f,0.2f,1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawNode(skyBox);
	drawNode(scene);
}

void Renderer::drawNode(SceneNode* node)
{
	if (node->GetMesh()) node->Draw(*this);

	for (vector<SceneNode*>::const_iterator i = node->GetChildIteratorStart(); i != node->GetChildIteratorEnd(); ++i)
		drawNode(*i);
}


