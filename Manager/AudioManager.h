#pragma once
#include <map>
#include <string>

/*
* defineでの定義例 
* #define AUDIO_BGM "bgm.mp3"
*/

class AudioManager {
private:
    std::map<std::string, int> audioMap;

    AudioManager();
    ~AudioManager();
public:
    static AudioManager& GetInstance();

    void Init();

    /// <summary>
    /// 動的にオーディオファイルを読む関数
    /// </summary>
    /// <param name="filePath">読みたいファイルパス</param>
    /// <returns></returns>
    int LoadAudio(const std::string& filePath);

    /// <summary>
    /// 
    /// </summary>
    /// <param name="fileName"></param>
    void PlayAudio(const std::string& fileName);
    void StopAudio(const std::string& fileName);
    void StopAllAudio();
    int GetAudioHandle(const std::string& fileName);

    void ChangeVolume(const std::string& fileName, int volume);
};