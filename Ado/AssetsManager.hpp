//   Code by Harding Adonis
//   E - mail: hardingadonis@gmail.com
//   Facebook:https://www.facebook.com/adonis.harding

#ifndef _AssetsManager_HPP_
#define _AssetsManager_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <map>

namespace ado
{
    class AssetsManager
    {
	protected:
		std::map <std::string, sf::Texture>       m_texture;
		std::map <std::string, sf::Image>         m_image;
		std::map <std::string, sf::Font>          m_font;
		std::map <std::string, sf::SoundBuffer>   m_sound_buffer;
		std::map <std::string, sf::Shader>        m_shader;

	public:
		AssetsManager();
		~AssetsManager();

		virtual void  push_Texture      (std::string ID_texture, std::string Path_File);
		virtual void  push_Image        (std::string ID_image, std::string Path_File);
		virtual void  push_Font         (std::string ID_font, std::string Path_File);
		virtual void  push_SoundBuffer  (std::string ID_sound_buffer, std::string Path_File);


		sf::Texture&       getTexture       (std::string ID);
		sf::Image&         getImage         (std::string ID);
		sf::Font&          getFont          (std::string ID);
		sf::SoundBuffer&   getSoundBuffer   (std::string ID);
    };
}

#endif // _AssetsManager_HPP_
