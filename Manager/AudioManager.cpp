#include "AudioManager.h"
#include <DxLib.h>
#include <string>

AudioManager::AudioManager() {
    
}

AudioManager::~AudioManager() {
    for (const auto& audio : audioMap) {
        DeleteSoundMem(audio.second);
    }
}

AudioManager& AudioManager::GetInstance() {
    static AudioManager instance;
    return instance;
}

void AudioManager::Init() {
    // LoadAudio("（パス名を指定する）");

    for (const auto& handle : audioMap) {
        PlaySoundMem(handle.second, DX_PLAYTYPE_LOOP);
    }
}

int AudioManager::LoadAudio(const std::string& filePath) {
    int handle = LoadSoundMem(filePath.c_str());
    if (handle == -1) {
        return -1;
    }
    std::string fileName = filePath.substr(filePath.find_last_of("/\\") + 1); // 最後のスラッシュの位置を見つけて、その次の文字以降を開始地点とする
    audioMap[fileName] = handle;
    return 0;
}

void AudioManager::PlayAudio(const std::string& fileName) {
    int handle = GetAudioHandle(fileName);
    if (handle != -1) {
        PlaySoundMem(handle, DX_PLAYTYPE_LOOP);
    }
}

void AudioManager::StopAudio(const std::string& fileName) {
    int handle = GetAudioHandle(fileName);
    if (handle != -1) {
        StopSoundMem(handle);
    }
}

void AudioManager::StopAllAudio() {
    for (const auto& audio : audioMap) {
        StopSoundMem(audio.second);
    }
}

int AudioManager::GetAudioHandle(const std::string& fileName) {
    auto it = audioMap.find(fileName);
    if (it != audioMap.end()) {
        return it->second;
    }
    return -1;
}

void AudioManager::ChangeVolume(const std::string& fileName, int volume) {
    int handle = GetAudioHandle(fileName);
    if (handle != -1) {
        ChangeVolumeSoundMem(volume, handle);
    }
}
