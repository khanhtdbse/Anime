//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com
//   Facebook:https://www.facebook.com/adonis.harding

#include "AssetsManager.hpp"

namespace ado
{
	AssetsManager::AssetsManager()
	{
		//   Constructor
	}

	AssetsManager::~AssetsManager()
	{
		//   Destructor
	}

	void AssetsManager::push_Texture(std::string ID_texture, std::string Path_File)
	{
		sf::Texture texture;
		if (texture.loadFromFile(Path_File))
			this->m_texture[ID_texture] = texture;
	}

	void AssetsManager::push_Image(std::string ID_image, std::string Path_File)
	{
		sf::Image image;
		if (image.loadFromFile(Path_File))
			this->m_image[ID_image] = image;

	}

	void AssetsManager::push_Font(std::string ID_font, std::string Path_File)
	{
        sf::Font font;
        if (font.loadFromFile(Path_File))
			this->m_font[ID_font] = font;
	}

	void AssetsManager::push_SoundBuffer(std::string ID_sound_buffer, std::string Path_File)
	{
		sf::SoundBuffer soundbuffer;
		if (soundbuffer.loadFromFile(Path_File))
			this->m_sound_buffer[ID_sound_buffer] = soundbuffer;
	}

	sf::Texture& AssetsManager::getTexture(std::string ID)
	{
        return this->m_texture.find(ID)->second;
	}

	sf::Image& AssetsManager::getImage(std::string ID)
	{
		return this->m_image.find(ID)->second;
	}

	sf::Font& AssetsManager::getFont(std::string ID)
	{
		return this->m_font.find(ID)->second;
	}

	sf::SoundBuffer& AssetsManager::getSoundBuffer(std::string ID)
	{
        return this->m_sound_buffer.find(ID)->second;
	}
}
