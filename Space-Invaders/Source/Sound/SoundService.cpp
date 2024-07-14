#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

namespace Sound
{
	using namespace Global;
	SoundService::SoundService()
	{
	}

	SoundService::~SoundService()
	{
	}

	void SoundService::playSound(SoundType type)
	{
		switch (type)
		{
		case Sound::SoundType::BUTTON_CLICK:
			sound_effect.setBuffer(button_click_buffer);
			break;
		case Sound::SoundType::BULLET_FIRE:
			sound_effect.setBuffer(bullet_fire_buffer);
			break;
		case Sound::SoundType::EXPLOSION:
			sound_effect.setBuffer(explosion_buffer);
			break;
		case Sound::SoundType::POWER_ENABLE:
			sound_effect.setBuffer(power_enable_buffer);
			break;
		case Sound::SoundType::POWER_DISABLE:
			sound_effect.setBuffer(power_disable_buffer);
			break;
		default:
			
			("Invalid Sound");
			break;
		}

		sound_effect.play();
	}

	void SoundService::backgroundSound()
	{
		background_music.setLoop(true);
		background_music.setVolume(volume);
		background_music.play();
	}


	void SoundService::initialize()
	{
		loadBackgroundMusic();
		loadSoundMusic();
	}

	void SoundService::loadBackgroundMusic()
	{
		if (!background_music.openFromFile(Config::background_music_path))
		{
			printf("Error in loading file");
		}
		
	}

	void SoundService::loadSoundMusic()
	{
		if (!button_click_buffer.loadFromFile(Config::button_click_sound_path))
		{
			printf("Error in loading Sound effect");
		}
		if (!bullet_fire_buffer.loadFromFile(Config::bullet_fire_sound))
		{
			printf("Error in loading Sound effect");
		}
		if (!explosion_buffer.loadFromFile(Config::explosion_sound))
		{
			printf("Error in loading Sound effect");
		}
		if (!power_enable_buffer.loadFromFile(Config::powerup_enable_sound))
		{
			printf("Error in loading Sound effect");
		}
		if (!power_disable_buffer.loadFromFile(Config::powerup_disable_sound))
		{
			printf("Error in loading Sound effect");
		}
		
	}
}

