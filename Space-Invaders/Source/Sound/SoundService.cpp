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
			sound_effect.setBuffer(sound_effect_buffer);
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
		if (!sound_effect_buffer.loadFromFile(Config::button_click_sound_path))
		{
			printf("Error in loading Sound effect");
		}
	}
}

