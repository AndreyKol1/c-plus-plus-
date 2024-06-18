#pragma once
#ifndef mainFunc_H
#define mainFunc_H
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Playlist.h"
#include "MusicTrack.h"
#include "PlayButton.h"
#include "MusicSearchBox.h"
#include "VolumeUpBTN.h"
#include "VolumeDownBTN.h"
#include "NextSong.h"
#include "PreviousSong.h"
#include "AddToPlaylist.h"
#include "RemoveBTN.h"
#include "ShowPlaylist.h"


#include <iostream>
#include <stack>



template <typename T>
void changeHover(T& button, const sf::Color& color);

void BTNPlay(sf::Music& music, sf::Texture& playTEXTURE, sf::Texture& pauseTEXTURE, const string& myStr, bool& isPlaying, bool& isPaused);

void addVolume(sf::Music& music, float& volume);

void reduceVolume(sf::Music& music, float& volume);

void addToPlaylist(Playlist& p1, sf::Music& music, string& myStr, sf::Texture& playTEXTURE, sf::Texture& pauseTEXTURE, bool& isPlaying);

void skipSong(vector<string>& mus, Playlist& p1, stack<string>& playedTracks, sf::Music& music);

void playPrevious(Playlist& p1, vector<string>& mus, stack<string>& playedTracks, sf::Music& music);

void removeSong(Playlist& p1, const string& myStr);

void displayPlaylist(Playlist& p1, vector<string>& mus);

void stopMus(bool& isPlaying, sf::Texture& playTEXTURE, sf::Texture& pauseTEXTURE, sf::Music& music);



#endif

template<typename T>
inline void changeHover(T& button, const sf::Color& color)
{
	button.SetBackColor(color);
}
