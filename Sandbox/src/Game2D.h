#pragma once

#include "Hazel.h"

class Game2D : public Hazel::Layer
{
public:
	Game2D();
	virtual ~Game2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Hazel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Hazel::Event& e) override;
private:
	Hazel::OrthographicCameraController m_CameraController;
	Hazel::ColorMap m_cmap;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
	float m_fps = 0.0f;
};