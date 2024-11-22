#include "Tree.h"

#include "Blank Project/Manager/ShaderManager.h"

Tree::Tree() : SceneNode(Mesh::LoadFromMeshFile("tree.obj"))
{
    shader = ShaderManager::GetSceneShader();
    if (!shader->LoadSuccess()) throw std::runtime_error("Tree shader failed to load!");
}

Tree::~Tree()
{
    delete mesh;
}
//
// void Tree::Draw(OGLRenderer& r)
// {
//     r.BindShader(shader);
//     
//     Matrix4 model = GetWorldTransform() * Matrix4::Scale(GetModelScale());
//     glUniformMatrix4fv(glGetUniformLocation(shader->GetProgram(), "modelMatrix"),
//     1, false, model.values);
//
//     glUniform4fv(glGetUniformLocation(shader->GetProgram(), "colour"),
//         1, (float*)&GetColour());
//     
//     glUniform1i(glGetUniformLocation(shader->GetProgram(), "diffuseTex"), 0);
//     glActiveTexture(GL_TEXTURE0);
//     glBindTexture(GL_TEXTURE_2D, texture);
//
//     glUniform3fv(glGetUniformLocation(shader->GetProgram(), "cameraPos"),
//         1, (float*)&(*camera)->GetPosition());
//
//     r.UpdateShaderMatrices();
//     
//         SceneNode::Draw(r);
// }


