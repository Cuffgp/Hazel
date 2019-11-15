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

	const int m_rows = 50, m_cols = 50;
	const glm::vec2 m_tileSize = { 0.03, 0.03 };
	const glm::vec2 m_tileScale = m_tileSize * 1.0f;
	const glm::vec2 m_boarderOffset = { 0.0, 0.0 };
	const glm::vec2 m_startOffset = glm::vec2{ -0.5, -0.5 };

	float m_fps = 0.0f;
};