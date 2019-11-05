#include "Game2D.h"

#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Game2D::Game2D()
	: Layer("Game2D"), m_CameraController(1280.0f / 720.0f), m_cmap("assets/colormap/MPL_jet.rgb", 0, 20)
{
}

void Game2D::OnAttach()
{

}

void Game2D::OnDetach()
{

}

void Game2D::OnUpdate(Hazel::Timestep ts)
{
	m_fps = 1.0f / ts;
	// Update
	m_CameraController.OnUpdate(ts);

	// Render

	Hazel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Hazel::RenderCommand::Clear();

	Hazel::Renderer2D::BeginScene(m_CameraController.GetCamera());

	for(int x=0; x < 10; x++)
		for (int y = 0; y < 10; y++)
		{
			m_SquareColor = m_cmap.Get(x + y);
			Hazel::Renderer2D::DrawQuad({x*0.11f - 0.5f, y*0.11f - 0.5f}, { 0.1f, 0.1f }, m_SquareColor);
		}
	

	Hazel::Renderer2D::EndScene();
}

void Game2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::Text("Framerate: %f fps", m_fps);
	//ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Game2D::OnEvent(Hazel::Event& e)
{
	m_CameraController.OnEvent(e);
}
