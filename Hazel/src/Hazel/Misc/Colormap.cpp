#include "hzpch.h"
#include "Colormap.h"

#include <fstream>


namespace Hazel {

	ColorMap::ColorMap(const std::string& filepath, float min, float max)
		:m_min(min), m_max(max)
	{
		this->Load(filepath, min, max);
	}

	void ColorMap::Load(const std::string& filepath, float min, float max)
	{
		int linecount = 1;
		std::string result;
		std::ifstream in(filepath, std::ios::in | std::ios::binary);

		float f1 = 0, f2 = 0, f3 = 0;
		size_t s1;
		std::string st2;

		if (in)
		{
			while (std::getline(in, result))
			{
				if (linecount == 1)
				{
					m_colors = std::stoi(result.substr(9)); // "ncolors= "
				}

				if (linecount > 2)
				{
					f1 = std::stof(result, &s1);
					st2 = result.substr(s1);
					f2 = std::stof(st2, &s1);
					f3 = std::stof(st2.substr(s1));
				}
				linecount++;

				glm::vec4 cvec(f1, f2, f3, 1.0f);
				m_Cmap.insert(std::pair<int, glm::vec4>(linecount - 3, cvec));
			}

		}
		else
		{
			HZ_CORE_ERROR("Could not open file '{0}'", filepath);
		}
	}

	glm::vec4 ColorMap::Get(float value)
	{
		

		if (value >= m_max)
			return m_Cmap[m_colors-1];
		else if (value <= m_min)
			return m_Cmap[0];
		else
		{
			float pos = ((value - m_min) / (m_max - m_min)) * (m_colors - 1);
			return m_Cmap[(int)pos];
		}
	}

}