#include "../NCLGL/window.h"
#include "Renderer.h"

int main()	{
	Window w("Alfie's Project", 1280, 720, false);

	if(!w.HasInitialised()) {
		return -1;
	}
	
	Renderer renderer(w);
	if(!renderer.HasInitialised()) {
		return -1;
	}

	w.LockMouseToWindow(true);
	w.ShowOSPointer(false);

	while(w.UpdateWindow()  && !Window::GetKeyboard()->KeyDown(KEYBOARD_ESCAPE)){
		renderer.UpdateScene(w.GetTimer()->GetTimeDeltaSeconds());
		renderer.RenderScene();
		renderer.SwapBuffers();
		if (Window::GetKeyboard()->KeyTriggered(KEYBOARD_1)) renderer.SetFreeCamera(true);
		if (Window::GetKeyboard()->KeyTriggered(KEYBOARD_2)) renderer.SetFreeCamera(false);
		if (Window::GetKeyboard()->KeyTriggered(KEYBOARD_3)) renderer.FlipScene();
		if (Window::GetKeyboard()->KeyDown(KEYBOARD_F5)) Shader::ReloadAllShaders();
	}
	return 0;
}