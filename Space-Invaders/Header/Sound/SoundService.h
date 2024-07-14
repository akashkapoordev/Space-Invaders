#pragma once
#include <SFML/Audio.hpp>

namespace Sound
{
	enum class SoundType
	{
		BUTTON_CLICK,
		BULLET_FIRE,
		EXPLOSION,
		POWER_ENABLE,
		POWER_DISABLE
	};

	class SoundService
	{
	public:
		SoundService();
		~SoundService();

		void playSound(SoundType type);
		void backgroundSound();

		void initialize();

	private:
		const int volume = 30;
		sf::Music background_music;
		sf::Sound sound_effect;
		sf::SoundBuffer button_click_buffer;
		sf::SoundBuffer bullet_fire_buffer;
		sf::SoundBuffer explosion_buffer;
		sf::SoundBuffer power_enable_buffer;
		sf::SoundBuffer power_disable_buffer;




		void loadBackgroundMusic();
		void loadSoundMusic();
	};

}
