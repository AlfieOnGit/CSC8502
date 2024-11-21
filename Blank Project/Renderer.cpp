#include "Renderer.h"

#include "Scene/Scene.h"
#include "Scene/Terrain.h"

Renderer::Renderer(Window &parent) : OGLRenderer(parent)	{

	// Terrain setup
	scene = new Scene(*this, camera);

	// Skybox setup
	skyBox = new SkyBox();

	// Camera setup
	//camera = new Camera(0, 0, terrain->GetHeightMapSize() * Vector3(0.5, 2, 0.5));
	camera = new Camera(0, 0, Vector3(1000, 1000, 1000));

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
	drawNode(scene, true);
}

void Renderer::drawNode(SceneNode* node, bool drawChildren)
{
	if (node->GetMesh()) node->Draw(*this);

	if (drawChildren)
		for (vector<SceneNode*>::const_iterator i = node->GetChildIteratorStart();
			i != node->GetChildIteratorEnd(); ++i)
				drawNode(*i);
}
