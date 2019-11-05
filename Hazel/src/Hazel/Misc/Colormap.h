#pragma once
#include <map>

#include <glm/glm.hpp>

namespace Hazel {

	class ColorMap
	{
	public:
		ColorMap(const std::string& filepath, float min, float max);

		void Load(const std::string& filepath, float min, float max);
		glm::vec4 Get(float value);

	private:
		int m_colors = 0;
		float m_min, m_max;
		std::map<int, glm::vec4> m_Cmap;
	};

}