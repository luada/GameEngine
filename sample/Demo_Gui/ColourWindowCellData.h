#ifndef __COLOUR_WINDOW_CELL_DATA_H__
#define __COLOUR_WINDOW_CELL_DATA_H__

#include <GUI.h>

namespace demo
{

	class ColourWindowCellData
	{
	public:
		ColourWindowCellData()
		{
		}

		ColourWindowCellData(const GUI::Colour& colour, const std::string& name) :
			m_colour(colour),
			m_name(name)
		{
		}

		const std::string& GetName() const { return m_name; }
		const GUI::Colour& GetColour() { return m_colour; }


	private:
		GUI::Colour m_colour;
		std::string m_name;

	};

} // namespace demo

#endif // __COLOUR_WINDOW_CELL_DATA_H__
